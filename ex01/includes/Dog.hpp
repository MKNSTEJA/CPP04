/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:57:00 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/21 19:20:22 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {
public:
  // Constructor and Destructors
  Dog();                           // Default constructor
  Dog(const std::string &type);    // Parametrised constructor
  Dog(const Dog &copy);            // Copy constructor
  Dog &operator=(const Dog &copy); // Assignment operator overload
  ~Dog();                          // Destructor

  void makeSound() const override; // Overriding base class function
};
