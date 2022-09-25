#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main( void )
{
	FragTrap fighter("Fighter 1");
	FragTrap first;

	first = fighter;
	first.attack("Fighter 2");
	first.takeDamage(10);
	first.beRepaired(10);
	first.highFivesGuys();
	
	return 0;
}
