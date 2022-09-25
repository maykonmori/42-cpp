#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(const Bureaucrat &ref);
	Bureaucrat &operator=(const Bureaucrat &ref);
	~Bureaucrat();

	class GradeTooHighException: public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		const char* what() const throw();
	};

	std::string getName(void) const;
	int getGrade() const;

	Bureaucrat &operator++ ();
	Bureaucrat &operator-- ();
	Bureaucrat operator++ (int);
	Bureaucrat operator-- (int);

	void	signForm(Form &form);
};

std::ostream & operator<<(std::ostream &out, Bureaucrat const &rhs);

#endif