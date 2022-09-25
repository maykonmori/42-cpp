#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain;
}

Dog::Dog(const Dog &ref) : Animal()
{
    std::cout << "Copy constructor Dog called" << std::endl;
    Animal::type = ref.Animal::getType();
    this->brain = new Brain;
    *this->brain = *ref.brain;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Destructor of Dog called" << std::endl;
}

Dog &Dog::operator=(Dog const &ref)
{
    std::cout << "Copy assignment operator (Dog) called" << std::endl;
    if (this != &ref)
    {
        Animal::type = ref.Animal::getType();
        *this->brain = *ref.brain;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << this->type << " makes sound: AU AU" << std::endl;
}

