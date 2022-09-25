#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_grade_sign;
	const int			_grade_exec;
public:
	Form();
	Form(std::string name, int grade_s, int grade_e);
	Form(const Form &ref);
	Form &operator=(const Form &ref);
	virtual ~Form();

	class GradeTooHighException: public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		const char* what() const throw();
	};
	class FormNotSigned: public std::exception
	{
		const char* what() const throw();
	};

	std::string getName()const;
	int getGradeSign()const;
	int getGradeExec()const;
	bool getSigned()const;

	void setSigned(bool s);
	void beSigned(const Bureaucrat &b);
	virtual	void execute(Bureaucrat const & executor) const = 0;
};

std::ostream	&operator<<(std::ostream &out, Form const &rhs);

#endif
