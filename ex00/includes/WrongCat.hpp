/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:11:36 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/21 19:19:46 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <iostream>

class WrongCat : public Animal {
public:
  // Constructor and Destructors
  WrongCat();                                // Default constructor
  WrongCat(const std::string &type);         // Parametrised constructor
  WrongCat(const WrongCat &copy);            // Copy constructor
  WrongCat &operator=(const WrongCat &copy); // Assignment operator overload
  ~WrongCat();                               // Destructor

  void makeSound() const; // Overriding base class function
};
