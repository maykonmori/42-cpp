#include  <iostream>
#include  "Bureaucrat.hpp"

/**
 * The above function creates two forms and two Bureaucrats. The first Bureaucrat is able to sign the
 * first form, but the second Bureaucrat is not able to sign the second form.
 * 
 * @return The program is returning 0.
 */
int main (void){
	try
	{
		Form form("form1", 10, 20);
		Bureaucrat Bureaucrat("Bureaucrat1", 5);
		Bureaucrat.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form form("form2", 10, 15);
		Bureaucrat Bureaucrat("Bureaucrat2", 20);
		Bureaucrat.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
