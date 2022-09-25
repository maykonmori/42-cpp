#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap fighter("Fighter 1");
	ClapTrap first;

	first = fighter;
	first.attack("Fighter 2");
	first.takeDamage(9);
	first.beRepaired(10);
	first.takeDamage(11);

	return(0);
}

