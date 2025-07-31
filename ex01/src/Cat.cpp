/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:06:21 by kmummadi          #+#    #+#             */
/*   Updated: 2025/07/31 13:34:28 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"
#include "../includes/utils.hpp"

// Default Constructor
Cat::Cat() : Animal(), _brain(new Brain()) {
  _type = "Cat";
  std::cout << "Cat: ";
  colorprint("Default constructor called\n", GREEN);
}

// Copy constructor
Cat::Cat(const Cat &copy) : Animal(copy), _brain(new Brain(*(copy._brain))) {
  std::cout << "Cat: ";
  colorprint("Copy constructor called\n", GREEN);
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &copy) {
  std::cout << "Cat: ";
  colorprint("Assignment operator overload called\n", GREEN);

  if (this != &copy)
    this->_type = copy.getType();
  if (_brain)
    delete _brain;
  _brain = new Brain(*(copy._brain));
  return (*this);
}

// Destructor
Cat::~Cat() {
  std::cout << "Cat: ";
  colorprint("Destructor called\n", GREEN);
  delete _brain;
}

// Override functions
void Cat::makeSound() const {
  std::cout << "Cat: ";
  colorprint("Miaaaauuuuu!\n", YELLOW);
}
