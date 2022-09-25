#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: Form("RobotomyRequestFormDefault", 75, 45)
{
	std::cout << "RobotomyRequestForm default constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form("RobotomyRequestForm", 45 , 72) , _target(target)
{
	std::cout << "RobotmyRequestForm constructor called with target = " << target << "\n";
	
}

RobotomyRequestForm		&RobotomyRequestForm::operator=(RobotomyRequestForm const &ref)
{
	std::cout << "RobotmyRequestForm assignation operator overload called!" << std::endl;
	if (this != &ref)
		*this = ref;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
: Form("RobotomyRequestForm", 45 , 72) , _target(ref.getTarget())
{
	*this = ref;
	std::cout << "RobotmyRequestForm assignation operator overload called!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor of RobotomyRequestForm called" <<std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw Form::FormNotSigned();
	if (executor.getGrade() >= this->getGradeExec())
		throw Form::GradeTooLowException();
    srand(time(NULL));
    int nbr = rand();
    if (nbr % 2 == 0)
    	std::cout << this->getTarget() << " has been robotomized successfully 50% of the time " << std::endl;
    else
		std::cout << "Robotomy failed" << std::endl;
}

std::string RobotomyRequestForm::getTarget()const {
	return (this->_target);
}