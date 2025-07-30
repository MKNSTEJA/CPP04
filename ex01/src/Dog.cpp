/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:11:06 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/21 19:30:35 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/utils.hpp"

// Default Constructor
Dog::Dog() : Animal("Dog") {
  std::cout << "Dog: ";
  colorprint("Default constructor called\n", GREEN);
}

// Parametrised constructor
Dog::Dog(const std::string &type) : Animal(type) {
  std::cout << "Dog: ";
  colorprint("Parametrised constructor called\n", GREEN);
}

// Copy constructor
Dog::Dog(const Dog &copy) : Animal(copy) {
  std::cout << "Dog: ";
  colorprint("Copy constructor called\n", GREEN);
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &copy) {
  std::cout << "Dog: ";
  colorprint("Assignment operator overload called\n", GREEN);

  if (this != &copy)
    this->_type = copy.getType();
  return (*this);
}

// Destructor
Dog::~Dog() {
  std::cout << "Dog: ";
  colorprint("Destructor called\n", GREEN);
}

// Override functions
void Dog::makeSound() const {
  std::cout << "Dog: ";
  colorprint("Woof!\n", YELLOW);
}
