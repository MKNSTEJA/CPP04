/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:50:05 by kmummadi          #+#    #+#             */
/*   Updated: 2025/07/31 14:31:49 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal {
private:
  Brain *_brain;

public:
  // Constructor and Destructors
  Cat();                           // Default constructor
  Cat(const Cat &copy);            // Copy constructor
  Cat &operator=(const Cat &copy); // Copy assignment operator overload
  ~Cat();                          // Destructor

  void makeSound() const override; // Overriding base class function

  // Getter and Setter for brain
  Brain *getBrain();
};
