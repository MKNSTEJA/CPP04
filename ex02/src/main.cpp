/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:16:35 by kmummadi          #+#    #+#             */
/*   Updated: 2025/07/31 16:05:01 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/utils.hpp"
#include <iostream>

int main() {
  // ─────────────────────────────────────────────────────────────────────────────
  // Test 1: Abstract Animal Instantiation (Compile-time Check)
  // ─────────────────────────────────────────────────────────────────────────────
  // What: Attempt to instantiate Animal directly (commented out).
  // Why: Animal is now abstract (makeSound() = 0) and should not be instantiable.
  // Expected:
  //   - If uncommented, `new Animal()` fails to compile with "abstract class" error.
  // Outcome:
  //   - Demonstrates Animal cannot be created on its own.
  section("Test 1: Abstract Animal Instantiation");
  {
    // const Animal* meta = new Animal(); // ← compile error: cannot instantiate abstract class
    colorprint("Animal is abstract; instantiation is disallowed at compile time.\n", GREEN);
  }

  // ─────────────────────────────────────────────────────────────────────────────
  // Test 2: Dog and Cat Creation & Deletion
  // ─────────────────────────────────────────────────────────────────────────────
  // What: Instantiate Dog and Cat via Animal* and delete them.
  // Why: Ensure concrete subclasses compile and their ctor/dtor chain works.
  // Expected:
  //   - Dog/Cat constructors print then destructor (via virtual) prints.
  section("Test 2: Dog & Cat Creation/Deletion");
  {
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    delete dog;  // Dog::~Dog → Animal::~Animal
    delete cat;  // Cat::~Cat → Animal::~Animal
  }

  // ─────────────────────────────────────────────────────────────────────────────
  // Test 3: makeSound() Polymorphism
  // ─────────────────────────────────────────────────────────────────────────────
  // What: Call makeSound() on Animal* pointing to Dog/Cat.
  // Why: Verify pure-virtual makeSound() dispatches to overrides.
  // Expected:
  //   - dog->makeSound() prints "Woof!"
  //   - cat->makeSound() prints "Miaaaauuuuu!"
  section("Test 3: makeSound() Polymorphism");
  {
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << "[Sound] Dog says: "; dog->makeSound();
    std::cout << "[Sound] Cat says: "; cat->makeSound();
    delete dog;
    delete cat;
  }

  return 0;
}
