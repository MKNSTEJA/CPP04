/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:18:52 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/21 19:20:02 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal {
protected:
  std::string _type;

public:
  // Constructors and Destructors
  WrongAnimal();                        // Default constructor
  WrongAnimal(const WrongAnimal &copy); // Copy constructor
  WrongAnimal &
  operator=(const WrongAnimal &copy); // Assignment operator overload
  virtual ~WrongAnimal();             // Destructor

  // Subject functions
  void makeSound() const;

  // Setters and Getters
  void setType(const std::string &type);
  std::string getType() const;
};
