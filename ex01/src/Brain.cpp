/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:46:38 by kmummadi          #+#    #+#             */
/*   Updated: 2025/07/31 13:07:12 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"
#include "../includes/utils.hpp"
#include <iostream>

// Default Constructor
Brain::Brain() {
  std::cout << "Brain: ";
  colorprint("Default constructor called\n", GREEN);
}

// Copy constructor
Brain::Brain(const Brain &other) {
  std::cout << "Brain: ";
  colorprint("Copy constructor called\n", GREEN);
  *this = other;
}

// Copy assignment operator overload
Brain &Brain::operator=(const Brain &other) {
  std::cout << "Brain: ";
  colorprint("Copy assingment operator called\n", GREEN);
  if (this != &other) {
    for (int i = 0; i < 100; ++i)
      this->_ideas[i] = other._ideas[i];
  }
  return (*this);
}

// Destructor
Brain::~Brain() {
  std::cout << "Brain: ";
  colorprint("Destructor called\n", GREEN);
}

// Getter and Setter functions
std::string Brain::getIdea(size_t i) const {
  if (i < 100)
    if (!_ideas[i].empty())
      return (_ideas[i]);
    else {
      std::cout << "Brain: ";
      colorprint("No idea available. It's empty!\n", YELLOW);
      return (nullptr);
    }
  else {
    std::cout << "Brain: ";
    colorprint("Invalid index provided\n", RED);
  }
  return (nullptr);
}

void Brain::setIdea(const std::string &idea, size_t i) {
  if (i < 100)
    _ideas[i] = idea;
  else
    colorprint("Wrong index provided\n", RED);
}
