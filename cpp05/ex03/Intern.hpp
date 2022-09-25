#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
protected:
	std::string requestsList[3];
	Form *createRobotomy(std::string target);
	Form *createPresidential(std::string target);
	Form *createShruberry(std::string target);
public:
    Intern();
	Intern(const Intern &ref);
	Intern	&operator=(Intern const &ref);
	Form *makeForm(std::string form_type, std::string name);
	~Intern();
};


#endif