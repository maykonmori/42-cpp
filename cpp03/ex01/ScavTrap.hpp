#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
    ScavTrap();
    ScavTrap(std::string const &name);
    ScavTrap(const ScavTrap &ref);
    ScavTrap &operator=(ScavTrap const &ref);
    ~ScavTrap();
    void guardGate();
    void attack(const std::string& target);
};

#endif 