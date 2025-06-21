/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:06:21 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/21 19:30:27 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/utils.hpp"

// Default Constructor
Cat::Cat() : Animal("Cat") {
  std::cout << "Cat: ";
  colorprint("Default constructor called\n", GREEN);
}

// Parametrised constructor
Cat::Cat(const std::string &type) : Animal(type) {
  std::cout << "Cat: ";
  colorprint("Parametrised constructor called\n", GREEN);
}

// Copy constructor
Cat::Cat(const Cat &copy) : Animal(copy) {
  std::cout << "Cat: ";
  colorprint("Copy constructor called\n", GREEN);
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &copy) {
  std::cout << "Cat: ";
  colorprint("Assignment operator overload called\n", GREEN);

  if (this != &copy)
    this->_type = copy.getType();
  return (*this);
}

// Destructor
Cat::~Cat() {
  std::cout << "Cat: ";
  colorprint("Destructor called\n", GREEN);
}

// Override functions
void Cat::makeSound() const {
  std::cout << "Cat: ";
  colorprint("Miaaaauuuuu!\n", YELLOW);
}
