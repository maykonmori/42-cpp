#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <iostream>
#include <cstdlib>

class RobotomyRequestForm : public Form
{
protected:
    std::string _target;
public:
    RobotomyRequestForm(/* args */);
    RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & ref);
    RobotomyRequestForm & operator=(RobotomyRequestForm const & ref);
    virtual ~RobotomyRequestForm();
    void execute(Bureaucrat const & executor) const;
    std::string getTarget()const ;
};

#endif