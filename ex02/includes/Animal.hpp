/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:42:16 by kmummadi          #+#    #+#             */
/*   Updated: 2025/07/31 15:22:22 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Animal {
protected:
  std::string _type;

public:
  // Constructors and Destructors
  Animal();                              // Default constructor
  Animal(const Animal &copy);            // Copy constructor
  Animal &operator=(const Animal &copy); // Assignment operator overload
  virtual ~Animal();                     // Destructor

  // Subject functions
  virtual void makeSound() const = 0;

  // Setters and Getters
  void setType(const std::string &type);
  std::string getType() const;
};
