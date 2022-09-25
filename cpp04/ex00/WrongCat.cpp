#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor of WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &ref) : WrongAnimal()
{
    std::cout << "Copy constructor WrongCat called" << std::endl;
    *this = ref;
}

WrongCat &WrongCat::operator=(WrongCat const &ref)
{
    std::cout << "Copy assignment operator (WrongCat) called" << std::endl;
    if (this != &ref)
        *this = ref;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << this->type << " make sound: rom-rom" << std::endl;
}