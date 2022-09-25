#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Destructor of Cat called" << std::endl;
}

Cat::Cat(const Cat &ref) : Animal()
{
    *this = ref;
    std::cout << "Copy constructor Cat called" << std::endl;
}

Cat &Cat::operator=(Cat const &ref)
{
    std::cout << "Copy assignment operator (Cat) called" << std::endl;
    if (this != &ref)
    {
        *this = ref;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << this->type << " make sound: MIAU" << std::endl;
}