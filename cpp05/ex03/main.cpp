#include  <iostream>
#include  "Bureaucrat.hpp"
#include  "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat *exec = new Bureaucrat("sed", 1);
	Intern someRandomIntern;
	Form* rrf = NULL;

	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		exec->signForm(*rrf);
		exec->executeForm(*rrf);	
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(char const* str)
	{
		std::cerr << str << '\n';
	}
	delete rrf;
	delete exec;
}
