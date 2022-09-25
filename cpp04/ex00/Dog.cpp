#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &ref) : Animal()
{
    *this = ref;
    std::cout << "Copy constructor Dog called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Destructor of Dog called" << std::endl;
}

Dog &Dog::operator=(Dog const &ref)
{
    std::cout << "Copy assignment operator (Dog) called" << std::endl;
    if (this != &ref)
    {
        *this = ref;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << this->type << "make sound: AU AU" << std::endl;
}

