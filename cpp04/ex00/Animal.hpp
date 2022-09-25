#if !defined(ANIMAL_HPP)
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(std::string const &name);
    Animal(const Animal &ref);
    Animal &operator=(Animal const &ref);
    virtual ~Animal();
    virtual void makeSound() const;
    std::string getType( void ) const;
};

#endif