/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:50:05 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/21 19:20:52 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal {
public:
  // Constructor and Destructors
  Cat();                           // Default constructor
  Cat(const std::string &type);    // Parametrised constructor
  Cat(const Cat &copy);            // Copy constructor
  Cat &operator=(const Cat &copy); // Assignment operator overload
  ~Cat();                          // Destructor

  void makeSound() const override; // Overriding base class function
};
