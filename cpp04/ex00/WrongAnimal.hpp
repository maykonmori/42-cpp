#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(std::string const &name);
	WrongAnimal(const WrongAnimal &ref);
	WrongAnimal &operator=(WrongAnimal const &ref);
	virtual ~WrongAnimal();
	void makeSound() const;
	std::string getType( void ) const;
};

#endif