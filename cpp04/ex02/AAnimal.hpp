#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
    std::string type;
public:
    AAnimal();
    AAnimal(std::string const &name);
    AAnimal(const AAnimal &ref);
    AAnimal &operator=(AAnimal const &ref);
    virtual ~AAnimal();
    virtual void makeSound() const = 0;
    std::string getType( void ) const;
};

#endif