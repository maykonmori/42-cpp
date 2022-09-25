#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called for " << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		this->_ideas[i] = "Ideas";
	}
}

Brain::~Brain()
{
	std::cout << "Destructor of Brain called" << std::endl;
}

Brain::Brain(const Brain &ref)
{
	std::cout << "Brain constructor by copy " << std::endl;
	*this = ref;
}

Brain &Brain::operator=(Brain const & ref)
{
	std::cout << "Assignation with operator called" << std::endl;
	if (this != &ref)
	{
		for (size_t i = 0; i < 100; i++)
			this->_ideas[i] = ref._ideas[i];
	}	
	return *this;
}