#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Constructor Default called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
	std::cout << "Contructor Copy called with values Name: " << name << " and Grade: " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref): _name(ref.getName()), _grade(ref.getGrade())
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
{
	std::cout << "Assignation with operator called" << std::endl;
	this->_grade = ref.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << " Destructor of Bureaucrat called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::string Bureaucrat::getName(void) const
{
	return(this->_name);
}

int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

Bureaucrat &Bureaucrat::operator++()
{
	this->_grade--;
	if(this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();	
	return(*this);
}

Bureaucrat &Bureaucrat::operator--()
{
	this->_grade++;
	if(this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return(*this);
}

Bureaucrat Bureaucrat::operator++ (int)
{
	Bureaucrat temp = *this;
	this->_grade --;
	if(this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return (temp);
}

Bureaucrat Bureaucrat::operator-- (int)
{
	Bureaucrat temp = *this;
	this->_grade++;
	if(this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return(temp);
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() <<" couldn’t sign "<< form.getName() << " because " << e.what() << std::endl;
	}
	
}

void	Bureaucrat::executeForm(Form const & form){
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() <<" couldn’t execute "<< form.getName() << " because " << e.what() << std::endl;
	}
}


std::ostream & operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (out);
}