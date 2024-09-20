#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) , _target(target)
{
	std::cout << CYAN << "PresidentialPardonForm constructor called" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	std::cout << CYAN << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	std::cout << CYAN << "PresidentialPardonForm assignation operator called" << RESET << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << CYAN << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << GREEN << this->_target << " has been pardoned by Zafod Beeblebrox" << RESET << std::endl;
}