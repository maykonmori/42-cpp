#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << "TEST SHRUBBERY CREATION" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Bs",13);
		std::cout << bureaucrat << std::endl;
		ShrubberyCreationForm shrubbery("Shrubbery");
		std::cout << shrubbery << std::endl;
		bureaucrat.signForm(shrubbery);
		bureaucrat.executeForm(shrubbery);
	}
	catch(std::exception& e1)
	{
		std::cerr << e1.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "TEST ROBOTOMY REQUEST" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Br",45);
		std::cout << bureaucrat << std::endl;
		RobotomyRequestForm robotomy("Robotomy");
		std::cout << robotomy << std::endl;
		bureaucrat.signForm(robotomy);
		bureaucrat.executeForm(robotomy);
	}
	catch(std::exception& e1)
	{
		std::cerr << e1.what() << '\n';
	}

	std::cout << "TEST PRESIDENTIAL PARDON" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Bp",3);
		std::cout << bureaucrat << std::endl;
		PresidentialPardonForm presidential("Presidential");
		std::cout << presidential << std::endl;
		bureaucrat.signForm(presidential);
		bureaucrat.executeForm(presidential);
		
	}
	catch(std::exception& e1)
	{
		std::cerr << e1.what() << '\n';
	}
}
