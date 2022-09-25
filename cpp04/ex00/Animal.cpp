#include "Animal.hpp"


Animal::Animal()
{
    std::cout << "Default Animal constructor called" << std::endl; 
    this->type = "Default Animal";
}

Animal::Animal(std::string const &name)
{
    std::cout << "Animal constructor called for " << name << std::endl; 
    this->type = name;
}

Animal::Animal(const Animal &ref)
{
    *this = ref;
    std::cout << "Copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Destructor of Animal called" << std::endl;
}

Animal  &Animal::operator=(Animal const &ref)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &ref)
    {
        *this = ref;
    }
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Make animal sound" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}