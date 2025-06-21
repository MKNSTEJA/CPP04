/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:14:05 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/21 19:30:51 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include "../includes/utils.hpp"

// Default Constructor
WrongAnimal::WrongAnimal() {
  std::cout << "WrongAnimal: ";
  colorprint("Default constructor called\n", GREEN);
}

// Parametrised constructor
WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
  std::cout << "WrongAnimal: ";
  colorprint("Parametrised constructor called\n", GREEN);
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy.getType()) {
  std::cout << "WrongAnimal: ";
  colorprint("Copy constructor called\n", GREEN);
}

// Assignment operator overload
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
  std::cout << "WrongAnimal: ";
  colorprint("Assignment operator overload called\n", GREEN);

  if (this != &copy)
    this->_type = copy.getType();
  return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal: ";
  colorprint("Destructor called\n", GREEN);
}

// Setters and Getters
void WrongAnimal::setType(const std::string &type) { this->_type = type; }

std::string WrongAnimal::getType() const { return (this->_type); }

void WrongAnimal::makeSound() const {
  colorprint(colortxt("Silence echoes\n", YELLOW), ITALIC);
}
