#include "Form.hpp"

Form::Form()
: _name("default"), _signed(false), _grade_sign(150), _grade_exec(150)
{
	std::cout << "Constructor Default called" << std::endl;
}

Form::Form(std::string name, int grade_s, int grade_e)
: _name(name), _signed(false), _grade_sign(grade_s), _grade_exec(grade_e)
{
	if (_grade_exec < 1 || _grade_sign < 1)
		throw Form::GradeTooHighException();
	else if (_grade_exec > 150 || _grade_sign > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called with values" << std::endl;
}

Form::Form(const Form &ref)
: _name(ref.getName()), _signed(ref.getSigned()), _grade_sign(ref.getGradeSign()), _grade_exec(ref.getGradeExec())
{
	if (_grade_exec < 1 || _grade_sign < 1)
		throw Form::GradeTooHighException();
	else if (_grade_exec > 150 || _grade_sign > 150)
		throw Form::GradeTooLowException();
	std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &ref)
{
  this->_signed = ref.getSigned();
  std::cout << "Assignation with operator called" << std::endl;
  return (*this);
}

Form::~Form()
{
	std::cout << " Destructor of Form called" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* Form::FormNotSigned::what() const throw()
{
	return ("Form not signed");
}

std::string Form::getName()const { return(this->_name); }

int Form::getGradeSign()const { return(this->_grade_sign); }

int Form::getGradeExec()const { return(this->_grade_exec); }

bool Form::getSigned()const { return(this->_signed); }

void Form::beSigned(const Bureaucrat &b)
{
  if (b.getGrade() <= this->getGradeSign())
	this->_signed = true;
  else
	throw Form::GradeTooLowException();
}

std::ostream & operator<<(std::ostream &out, Form const &rhs)
{
	out << "Form: " << rhs.getName() << std::endl;
	out << "Grade to sign: " << rhs.getGradeSign() << std::endl;
	out << "Grade to exec: " << rhs.getGradeExec() << std::endl;
	return (out);
}