#include "AAnimal.hpp"


AAnimal::AAnimal()
{
    std::cout << "Default AAnimal constructor called" << std::endl; 
    this->type = "Default AAnimal";
}

AAnimal::AAnimal(std::string const &name)
{
    std::cout << "AAnimal constructor called for " << name << std::endl; 
    this->type = name;
}

AAnimal::AAnimal(const AAnimal &ref)
{
    *this = ref;
    std::cout << "Copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "Destructor of AAnimal called" << std::endl;
}

AAnimal  &AAnimal::operator=(AAnimal const &ref)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &ref)
    {
        *this = ref;
    }
    return *this;
}

// void AAnimal::makeSound() const
// {
//     std::cout << "Make Aanimal sound" << std::endl;
// }

std::string AAnimal::getType(void) const
{
    return (this->type);
}