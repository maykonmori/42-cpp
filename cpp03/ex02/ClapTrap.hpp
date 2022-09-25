#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
protected:
	std::string name;
	unsigned int _attack;
	unsigned int energy;
	unsigned int life_points;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &ref);
	ClapTrap	&operator=(ClapTrap const &ref);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName(void) const;
	unsigned int getAttack(void) const;
	unsigned int getEnergy(void) const;
	unsigned int getLifePoints(void) const;

	void setName(std::string const &name);
	void setAttack(unsigned int _attack);
	void setEnergy(unsigned int energy);
	void setLifePoints(unsigned int life_points);

};

#endif