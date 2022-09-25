#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{   
protected:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &ref);
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &ref);
	virtual ~ShrubberyCreationForm();
	virtual	void execute(Bureaucrat const & executor) const;
	std::string getTarget()const;
};

#endif