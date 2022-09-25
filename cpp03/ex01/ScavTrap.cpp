#include "ScavTrap.hpp"


ScavTrap::ScavTrap()
: ClapTrap()
{
	this->setName("Default ScavTrap");
	this->setAttack(20);
	this->setEnergy(20);
	this->setLifePoints(100);
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name)
: ClapTrap(name)
{
	this->setAttack(20);
	this->setEnergy(20);
	this->setLifePoints(100);
	std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref)
: ClapTrap()
{
	*this = ref;
	std::cout << "ScavTrap constructor by copy" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap " << this->name << " called" <<std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &ref)
{
	if (this != &ref)
		ClapTrap::operator=(ref);
	return *this;
}

void ScavTrap::guardGate() 
{
	std::cout << "ScavTrap " << this->name << " in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->energy >= 1){
		std::cout << "ScavTrap " << this->name;
		std::cout << " attack " << target;
		std::cout << " causing " << this->_attack << " points of damage" << std::endl;
		this->energy--;
	} else{
		std::cout << "ScavTrap " << this->name;
		std::cout << "it's out of energy" << this->name << std::endl;
	}
}
