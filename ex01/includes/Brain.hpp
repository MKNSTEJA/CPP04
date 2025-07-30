/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:05:27 by kmummadi          #+#    #+#             */
/*   Updated: 2025/07/30 13:05:27 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Brain {
private:
  std::string _ideas[100];

public:
  Brain();                              // Default constructor
  Brain(const Brain &other);            // Copy constructor
  Brain &operator=(const Brain &other); // Copy assignment operator overload
  ~Brain();                             // Destructor

  void setIdea(std::string idea, int i);
  std::string getIdea(int i);
}
