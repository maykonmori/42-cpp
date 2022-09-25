#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap fighter("Fighter 1");
	ScavTrap first;

	first = fighter;
	first.attack("Fighter 2");
	first.takeDamage(9);
	first.beRepaired(10);
	first.takeDamage(11);
	first.guardGate();

	return(0);
}