#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    this->setName("Default FragTrap");
    this->setAttack(30);
    this->setEnergy(100);
    this->setLifePoints(100);
    std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const &name): ClapTrap(name)
{
    this->setAttack(30);
    this->setEnergy(100);
    this->setLifePoints(100);
    std::cout << "FragTrap constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref): ClapTrap()
{
    *this = ref;
    std::cout << "FragTrap constructor by copy" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor of FragTrap " << this->name << " called" << std::endl;
}

FragTrap    &FragTrap::operator=(FragTrap const &ref)
{
    if(this != &ref)
        ClapTrap::operator=(ref);
    return *this;
}
 
void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->name << " : High Fives Guys!!!" << std::endl;
}