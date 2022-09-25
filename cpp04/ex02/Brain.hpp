#ifndef BRAIN_HPP
# define BRAIN_HPP

#include<iostream>

class Brain
{
protected:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain &ref);
	Brain &operator=(Brain const &ref);
	~Brain();
	std::string getIdea(int const &id) const;
	void setIdea(int const &id, std::string const &ideas);
};

#endif