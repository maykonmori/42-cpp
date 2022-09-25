#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string const &name);
    FragTrap(const FragTrap &ref);
    FragTrap	&operator=(FragTrap const &rsh);
    ~FragTrap();
    void highFivesGuys();
};

#endif
