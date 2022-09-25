#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat &ref);
    WrongCat &operator=(WrongCat const &ref);
    ~WrongCat();
    void makeSound() const;
};

#endif