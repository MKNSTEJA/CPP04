/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:12:39 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/21 19:30:43 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"
#include "../includes/utils.hpp"

// Default Constructor
WrongCat::WrongCat() : WrongAnimal("Wrong Cat") {
  std::cout << "WrongCat: ";
  colorprint("Default constructor called\n", GREEN);
}

// Parametrised constructor
WrongCat::WrongCat(const std::string &type) : WrongAnimal(type) {
  std::cout << "WrongCat: ";
  colorprint("Parametrised constructor called\n", GREEN);
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
  std::cout << "WrongCat: ";
  colorprint("Copy constructor called\n", GREEN);
}

// Assignment operator overload
WrongCat &WrongCat::operator=(const WrongCat &copy) {
  std::cout << "WrongCat: ";
  colorprint("Assignment operator overload called\n", GREEN);

  if (this != &copy)
    this->_type = copy.getType();
  return (*this);
}

// Destructor
WrongCat::~WrongCat() {
  std::cout << "WrongCat: ";
  colorprint("Destructor called\n", GREEN);
}

// Override functions
void WrongCat::makeSound() const {
  std::cout << "WrongCat: ";
  colorprint("Raaaawrrr!\n", YELLOW);
}
