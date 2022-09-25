#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal()
{
    std::cout << "Default WrongAnimal constructor called" << std::endl; 
    this->type = "Default WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string const &name)
{
    std::cout << "WrongAnimal constructor called for " << name << std::endl; 
    this->type = name;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = ref;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor of WrongAnimal called" << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(WrongAnimal const &ref)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &ref)
        *this = ref;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Make WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}