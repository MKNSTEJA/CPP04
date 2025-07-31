/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:10:10 by kmummadi          #+#    #+#             */
/*   Updated: 2025/07/31 14:51:40 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/utils.hpp"
#include <iostream>

int main() {
  // ─────────────────────────────────────────────────────────────────────────────
  // Test 1: Constructor & Virtual Destructor Check
  // ─────────────────────────────────────────────────────────────────────────────
  // What: Create Animal pointers to Dog and Cat, then delete them.
  // Why: Verifies that Dog/Cat constructors chain to Animal, and that deleting
  //      via Animal* invokes the derived destructor first (i.e. Animal~ is virtual).
  // Expected:
  //   - Console shows Animal ctor, Dog/Cat ctor.
  //   - On delete, Dog/Cat dtor then Animal dtor.
  section("Test 1: Constructor & Virtual Destructor Check");
  {
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();
    delete dog;
    delete cat;
  }

  // ─────────────────────────────────────────────────────────────────────────────
  // Test 2: makeSound() with Animal pointers
  // ─────────────────────────────────────────────────────────────────────────────
  // What: Build an array of mixed Dog and Cat as Animal*.
  // Why: Ensures runtime polymorphism — makeSound() dispatches to the correct
  //      override in Dog or Cat.
  // Expected:
  //   - For each slot, type() reports "Dog"/"Cat" and makeSound() prints
  //     "Woof!" or "Miaaaauuuuu!" respectively.
  section("Test 2: makeSound() with Animal pointers");
  {
    const Animal *zoo[4];
    for (int i = 0; i < 4; ++i){
      if (i % 2 == 0)
        zoo[i] = new Dog();  // upcasts Dog* → Animal*
      else
        zoo[i] = new Cat();  // upcasts Cat* → Animal*
    }
    for (int i = 0; i < 4; ++i) {
      std::cout << "[Sound] " << zoo[i]->getType() << ": ";
      zoo[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i)
      delete zoo[i];
  }

  // ─────────────────────────────────────────────────────────────────────────────
  // Test 3: Dog Deep Copy via getBrain()
  // ─────────────────────────────────────────────────────────────────────────────
  // What: Use getBrain()->setIdea() to populate original, then copy-construct.
  // Why: Validates that Dog copy constructor performs a deep copy of Brain.
  // Expected:
  //   - original.brain[0] changes to "Eat treat" after copy.
  //   - copy.brain[0] remains "Chase tail".
  section("Test 3: Dog Deep Copy via getBrain()");
  {
    Dog original;
    // populate original's Brain
    original.getBrain()->setIdea("Chase tail", 0);
    original.getBrain()->setIdea("Dig hole",   1);

    Dog copy = original;              // deep-copy ctor
    original.getBrain()->setIdea("Eat treat", 0); // mutate original

    std::cout << "[Original] Idea 0: "
              << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "[Copy]     Idea 0: "
              << copy.getBrain()->getIdea(0) << std::endl;
  }

  // ─────────────────────────────────────────────────────────────────────────────
  // Test 4: Cat Deep Assignment via getBrain()
  // ─────────────────────────────────────────────────────────────────────────────
  // What: Assign one Cat to another using getBrain()-> for ideas.
  // Why: Ensures Cat operator= does deep copy of Brain.
  // Expected:
  //   - After a = b;, changing a.brain[0] does not affect b.brain[0].
  section("Test 4: Cat Deep Assignment via getBrain()");
  {
    Cat a;
    a.getBrain()->setIdea("Sleep on laptop", 0);

    Cat b;
    b = a; // deep-copy assignment
    a.getBrain()->setIdea("Knock glass", 0); // mutate a

    std::cout << "[Cat A] Idea 0: "
              << a.getBrain()->getIdea(0) << std::endl;
    std::cout << "[Cat B] Idea 0: "
              << b.getBrain()->getIdea(0) << std::endl;
  }

  return 0;
}
