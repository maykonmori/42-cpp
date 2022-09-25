#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Destructor of Cat called" << std::endl;
}

Cat::Cat(const Cat &ref) : AAnimal()
{
    std::cout << "Copy constructor Cat called" << std::endl;
    AAnimal::type = ref.AAnimal::getType();
    this->brain = new Brain;
    *this->brain = *ref.brain;
}

Cat &Cat::operator=(Cat const &ref)
{
    std::cout << "Copy assignment operator (Cat) called" << std::endl;
    if (this != &ref)
    {
        AAnimal::type = ref.AAnimal::getType();
        *this->brain = *ref.brain;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << this->type << " makes sound: MIAU" << std::endl;
}