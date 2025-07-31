/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:57:00 by kmummadi          #+#    #+#             */
/*   Updated: 2025/07/31 14:31:54 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
private:
  Brain *_brain;

public:
  // Constructor and Destructors
  Dog();                           // Default constructor
  Dog(const Dog &copy);            // Copy constructor
  Dog &operator=(const Dog &copy); // Assignment operator overload
  ~Dog();                          // Destructor

  void makeSound() const override; // Overriding base class function

  // Getter for brain
  Brain *getBrain();
};
