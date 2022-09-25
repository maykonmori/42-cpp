#include "Bureaucrat.hpp"

int main (void){
	try
	{
		Bureaucrat test("Claudio", 1);
		test++;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << std::endl;
	}
	
	try
	{
		Bureaucrat test("Joao", 150);
		test--;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << std::endl;
	}

	try
	{
		Bureaucrat test("Maria", 10);
		std::cout << test;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << std::endl;
	}
	
	return (0);
}