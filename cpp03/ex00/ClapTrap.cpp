#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
: name("Default ClapTrap"), _attack(0), energy(10), life_points(10)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: name(name), _attack(0), energy(10), life_points(10)
{
	std::cout << "Constructor called for ClapTrap(" << name << ")" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &ref)
: name(ref.name), _attack(ref._attack), energy(ref.energy), life_points(ref.life_points)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor of ClapTrap " << this->name << " called" << std::endl;
}

ClapTrap		&ClapTrap::operator=(ClapTrap const &ref)
{
	std::cout << "Copy assignment operator called " <<std::endl;
	if (this != &ref)
	{
		this->name = ref.getName();
		this->life_points = ref.getLifePoints();
		this->energy = ref.getEnergy();
		this->_attack = ref.getAttack();
	}
	return *this;
}

void ClapTrap::attack(const std::string& target){
	if (this->getEnergy() >= 1){
		std::cout << "ClapTrap " << this->getName();
		std::cout << " attacks " << target;
		std::cout << " causing " << this->getAttack() << " points of damage" << std::endl;
		this->energy--;
	} else {
		std::cout << "ClapTrap " << this->getName();
		std::cout << "it's out of energy" << this->getName();
	}

}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->getLifePoints() > amount){
		std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage" << std::endl;
		this->life_points -= amount;
	} else {
		std::cout << "ClapTrap " << this->getName();
		std::cout << " is dead" << std::endl;
		this->life_points = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->getEnergy() >= 1){
		std::cout << "ClapTrap " << this->getName();
		std::cout << " repaired hit in " << amount << std::endl;
		this->energy--;
		this->life_points += amount;
	}
	else {
		std::cout << "ClapTrap " << this->getName();
		std::cout << "it's out of energy" << this->name;
	}
}

std::string ClapTrap::getName(void) const
{
	return (this->name);
}

unsigned int ClapTrap::getAttack(void) const
{
	return (this->_attack);
}

unsigned int ClapTrap::getEnergy(void) const
{
	return (this->energy);
}

unsigned int ClapTrap::getLifePoints(void) const
{
	return (this->life_points);
}

void ClapTrap::setName(std::string const &name)
{
	this->name = name;
}

void ClapTrap::setAttack(unsigned int _attack)
{
	this->_attack = _attack;
}

void ClapTrap::setEnergy(unsigned int energy)
{
	this->energy = energy;
}

void ClapTrap::setLifePoints(unsigned int life_points)
{
	this->life_points = life_points;
}