#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: Form("PresidentialPardonNameDef", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
: Form("PresidentialPardonForm", 25, 5), _target(ref.getTarget())
{
	*this = ref;
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	std::cout << "Assignation with operator called" <<std::endl;
	if (this != &ref)
		*this = ref;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called!" << std::endl;
}

std::string PresidentialPardonForm::getTarget()const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{	
	if (!this->getSigned())
		throw Form::FormNotSigned();
	if (executor.getGrade() >= this->getGradeExec())
		throw Form::GradeTooLowException();
	std::cout << "Informs that " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}