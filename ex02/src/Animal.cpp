/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:58:38 by kmummadi          #+#    #+#             */
/*   Updated: 2025/07/31 15:20:36 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/utils.hpp"

// Default Constructor
Animal::Animal() {
  std::cout << "Animal: ";
  colorprint("Default constructor called\n", GREEN);
}

// Copy constructor
Animal::Animal(const Animal &copy) : _type(copy.getType()) {
  std::cout << "Animal: ";
  colorprint("Copy constructor called\n", GREEN);
}

// Assignment operator overload
Animal &Animal::operator=(const Animal &copy) {
  std::cout << "Animal: ";
  colorprint("Assignment operator overload called\n", GREEN);

  if (this != &copy)
    this->_type = copy.getType();
  return (*this);
}

// Destructor
Animal::~Animal() {
  std::cout << "Animal: ";
  colorprint("Destructor called\n", GREEN);
}

// Setters and Getters
void Animal::setType(const std::string &type) { this->_type = type; }

std::string Animal::getType() const { return (this->_type); }

void Animal::makeSound() const {
  std::cout << "Animal: ";
  colorprint("Silence echoes....\n", YELLOW + ITALIC);
}
