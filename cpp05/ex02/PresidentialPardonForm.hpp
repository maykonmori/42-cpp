#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
    std::string _target;    
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &ref);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);
    ~PresidentialPardonForm();
    virtual	void execute(Bureaucrat const & executor) const;
    std::string getTarget()const;
};

#endif