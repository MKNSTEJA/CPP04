/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:16:35 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/21 19:38:53 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/utils.hpp"
#include <iostream>

int main() {
  // Test 1: Instantiation & Cleanup
  // This verifies that:
  //  - Animal (base), Dog, and Cat constructors are called in correct order.
  //  - Each object initializes its `type` attribute properly.
  //  - Destructors are invoked in reverse order, demonstrating proper cleanup.
  section("Test 1: Instantiation & Cleanup");
  {
    // Create one instance of each class
    const Animal *meta =
        new Animal();              // Should output Animal constructor message
    const Animal *dog = new Dog(); // Should output Animal then Dog constructor
    const Animal *cat = new Cat(); // Should output Animal then Cat constructor

    // Check runtime type information
    std::cout << "[Check] Dog type is: " << dog->getType() << std::endl;
    std::cout << "[Check] Cat type is: " << cat->getType() << std::endl;

    // Delete instances to trigger destructors
    delete meta; // Only Animal destructor
    delete dog;  // Dog then Animal destructor via virtual
    delete cat;  // Cat then Animal destructor via virtual
  }

  // Test 2: makeSound() Polymorphism
  // Ensures that calling makeSound on base pointers
  // dispatches to the correct derived implementation when virtual,
  // and to the base implementation otherwise.
  section("Test 2: makeSound() Polymorphism");
  {
    const Animal *dog = new Dog();     // Should bark
    const Animal *cat = new Cat();     // Should meow
    const Animal *meta = new Animal(); // Generic animal noise

    // Expected outputs in order:
    // "Woof!" (Dog), "Meow!" (Cat), "Some generic animal sound" (Animal)
    dog->makeSound();
    cat->makeSound();
    meta->makeSound();

    delete dog;
    delete cat;
    delete meta;
  }

  // Test 3: Polymorphic Array of Animals
  // Demonstrates uniform interface: mix Dog and Cat in an array of Animal*.
  // Implicit upcasting allows Dog* → Animal* without explicit cast.
  section("Test 3: Polymorphic Array of Animals");
  {
    const Animal *zoo[6];
    for (int i = 0; i < 6; ++i) {
      // Even indices: Dog; Odd indices: Cat
      if (i % 2 == 0)
        zoo[i] = new Dog(); 
      else
        zoo[i] = new Cat();
    }
    for (int i = 0; i < 6; ++i) {
      std::cout << "[Zoo] " << zoo[i]->getType() << " says: ";
      zoo[i]->makeSound(); // Correct sound for each
    }
    // Clean up all animals
    for (int i = 0; i < 6; ++i) {
      delete zoo[i];
    }
  }

  // Test 4: WrongAnimal / WrongCat Non-Virtual Behavior
  // Shows that WrongCat does not override makeSound when base uses non-virtual,
  // illustrating the need for virtual functions in polymorphism.
  section("Test 4: WrongAnimal Non-Virtual Behavior");
  {
    const WrongAnimal *wrong = new WrongAnimal(); // Base class
    const WrongAnimal *wcat =
        new WrongCat(); // Derived, but makeSound not virtual

    // Types should reflect class names
    std::cout << "[Wrong] WrongAnimal type: " << wrong->getType() << std::endl;
    std::cout << "[Wrong] WrongCat type:    " << wcat->getType() << std::endl;

    // Both calls invoke WrongAnimal::makeSound(), not WrongCat
    wrong->makeSound(); // Expected: WrongAnimal sound
    wcat->makeSound();  // Expected: WrongAnimal sound again

    delete wrong;
    delete wcat;
  }

  // Test 5: Virtual Destructor Invocation
  // Confirms that deleting derived object through base pointer
  // correctly calls derived destructor first, then base destructor.
  section("Test 5: Virtual Destructor Invocation");
  {
    Dog *d1 = new Dog(); // Construct Dog
    Animal *a1 = d1;     // Upcast to Animal*
    delete a1;           // Should call Dog::~Dog then Animal::~Animal
  }

  return 0;
}
