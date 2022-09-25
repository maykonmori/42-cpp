#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: Form("ShrubberyCreationNameDef", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ref)
: Form("ShrubberyCreationForm", 137 , 145), _target(ref.getTarget())
{
	std::cout << "ShrubberyCreationForm contructor by copy" << std::endl;
	*this = ref;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called!" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ref)
{
	std::cout << "ShrubberyCreationForm assignation operator overload called!" << std::endl;
	if (this != &ref)
		*this = ref;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw Form::FormNotSigned();
	if (executor.getGrade() >= this->getGradeExec())
		throw Form::GradeTooLowException();
	std::string fd = this->getTarget() + "_shrubbery";
	std::ofstream outFile(fd.c_str());
	if (outFile.is_open())
	{
	outFile << "       ###       " << std::endl;
	outFile << "      #o###      " << std::endl;
	outFile << "    #####o###    " << std::endl;
	outFile << "   #o## |#/###   " << std::endl;
	outFile << "    ### |/#o#    " << std::endl;
	outFile << "     # }|{  #    " << std::endl;
	outFile << "       }|{       " << std::endl;
	}
}

std::string ShrubberyCreationForm::getTarget()const
{
	return (this->_target);
}