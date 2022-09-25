#if !defined(DOG_HPP)
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
    Brain *brain;
public:
    Dog();
    Dog(const Dog &ref);
    Dog &operator=(Dog const &ref);
    ~Dog();
    void makeSound()const;
};

#endif