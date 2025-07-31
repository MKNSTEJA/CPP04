/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:11:06 by kmummadi          #+#    #+#             */
/*   Updated: 2025/07/31 14:51:24 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/utils.hpp"

// Default Constructor
Dog::Dog() : Animal(), _brain(new Brain()) {
  _type = "Dog";
  std::cout << "Dog: ";
  colorprint("Default constructor called\n", GREEN);
}

// Copy constructor
Dog::Dog(const Dog &copy) : Animal(copy), _brain(new Brain(*(copy._brain))) {
  std::cout << "Dog: ";
  colorprint("Copy constructor called\n", GREEN);
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &copy) {
  std::cout << "Dog: ";
  colorprint("Assignment operator overload called\n", GREEN);

  if (this != &copy)
    this->_type = copy.getType();
  if (_brain)
    delete _brain;
  _brain = new Brain(*(copy._brain));
  return (*this);
}

// Destructor
Dog::~Dog() {
  std::cout << "Dog: ";
  colorprint("Destructor called\n", GREEN);
  delete _brain;
}

// Override functions
void Dog::makeSound() const {
  std::cout << "Dog: ";
  colorprint("Woof!\n", YELLOW);
}

// Getter for Brain
Brain *Dog::getBrain() { return (_brain); }
