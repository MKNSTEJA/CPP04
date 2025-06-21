# ————————————————— CONFIG —————————————————
NAME      := polymorphism                     
CXX       := c++
CXXFLAGS  := -Wall -Wextra -Werror -std=c++17 -Iincludes

SRC_DIR   := src
OBJ_DIR   := obj

# List your project .cpp's here (relative to SRC_DIR)
SRCS := \
	main.cpp \
	Animal.cpp \
	Cat.cpp \
	Dog.cpp \
	utils.cpp \
	WrongAnimal.cpp \
	WrongCat.cpp \

# derived paths
SRC_PATHS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ_PATHS := $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEP_FILES := $(OBJ_PATHS:.o=.d)

# spinner frames
SPINNER   := ⠋ ⠙ ⠹ ⠸ ⠼ ⠴ ⠦ ⠧ ⠏

# ANSI colors
GREEN     := \033[1;32m
YELLOW    := \033[1;33m
CYAN      := \033[1;36m
RESET     := \033[0m

# ————————————————— PHONY TARGETS —————————————————
.PHONY: all clean fclean re

# ————————————————— DEFAULT —————————————————
all: $(NAME)

# ————————————————— LINK WITH SPINNER —————————————————
$(NAME): $(OBJ_PATHS)
	@echo -n "$(CYAN)Linking $(NAME)... $(RESET)"
	@$(CXX) $(CXXFLAGS) $^ -o $@ 2>/dev/null & \
	 pid=$$!; \
	 while kill -0 $$pid 2>/dev/null; do \
	   for frame in $(SPINNER); do \
	     printf "\b%s" $$frame; \
	     sleep 0.1; \
	   done; \
	 done; \
	 printf "\b$(GREEN)✅\n$(RESET)"

# ————————————————— COMPILE —————————————————
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo -e "$(YELLOW)⏳ Compiling $<$(RESET)"
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# ————————————————— CLEANUP —————————————————
clean:
	@echo "🧹 Removing object files..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🧹 Removing executable..."
	@rm -f $(NAME)

re: fclean all

# ————————————————— INCLUDE DEPENDENCIES —————————————————
-include $(DEP_FILES)
