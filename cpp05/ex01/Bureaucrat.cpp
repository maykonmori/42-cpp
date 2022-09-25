#include "Bureaucrat.hpp"

/**
 * Constructor Default called
 */
Bureaucrat::Bureaucrat()
{
	std::cout << "Constructor Default called" << std::endl;
}

/**
 * This function is the constructor for the Bureaucrat class
 * 
 * @param name The name of the bureaucrat.
 * @param grade The grade of the bureaucrat.
 */
Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
	std::cout << "Contructor Copy called with values Name: " << name << " and Grade: " << grade << std::endl;
}

/**
 * Copy constructor called when a new object is created from an existing object, as a copy of the
 * existing object
 * 
 * @param ref The reference to the object that's being copied.
 */
Bureaucrat::Bureaucrat(const Bureaucrat &ref): _name(ref.getName()), _grade(ref.getGrade())
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Copy constructor called" << std::endl;
}

/**
 * It assigns the value of the grade of the Bureaucrat passed as a parameter to the Bureaucrat on which
 * the function is called.
 * 
 * @return A reference to the object that was assigned to.
 */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
{
	std::cout << "Assignation with operator called" << std::endl;
	this->_grade = ref.getGrade();
	return *this;
}

/**
 * The destructor of Bureaucrat is called
 */
Bureaucrat::~Bureaucrat()
{
	std::cout << " Destructor of Bureaucrat called" << std::endl;
}

/**
 * It's a constructor that takes a string as a parameter and sets it as the error message
 * 
 * @return A const char*
 */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

/**
 * It's a constructor that takes a string as a parameter and sets it as the error message
 * 
 * @return a const char*
 */
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/**
 * GetName returns the name of the Bureaucrat.
 * 
 * @return The name of the bureaucrat.
 */
std::string Bureaucrat::getName(void) const
{
	return(this->_name);
}

/**
 * GetGrade returns the value of the private member _grade.
 * 
 * @return The grade of the bureaucrat.
 */
int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

/**
 * It increments the grade of the bureaucrat by 1.
 * 
 * @return A reference to the object that was incremented.
 */
Bureaucrat &Bureaucrat::operator++()
{
	this->_grade--;
	if(this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();	
	return(*this);
}

/**
 * It increments the grade by 1.
 * 
 * @return A reference to the object that was incremented.
 */
Bureaucrat &Bureaucrat::operator--()
{
	this->_grade++;
	if(this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return(*this);
}

/**
 * A postfix increment operator. It returns the value of the object before the increment.
 * 
 * @param  int - This is the number of times the function is called.
 * 
 * @return A copy of the object.
 */
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

/**
 * A postfix decrement operator. It returns the value of the object before the decrement.
 * 
 * @param  - `int`: This is a dummy parameter. It's used to differentiate between the prefix and
 * postfix versions of the operator.
 * 
 * @return A copy of the object.
 */
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

/**
 * It tries to sign a form, and if it fails, it prints an error message
 * 
 * @param form The form to sign
 */
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

std::ostream & operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (out);
}