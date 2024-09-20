# include "RobotomyRequestForm.hpp"
# include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::srand(std::time(0));
	std::cout << CYAN << "RobotomyRequestForm constructor called" << RESET << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	std::cout << CYAN << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << CYAN << "RobotomyRequestForm assignation operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << CYAN << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << CYAN << "Drilling noises" << RESET << std::endl;
	if (std::rand() % 2)
		std::cout << CYAN << this->_target << " has been robotomized successfully" << RESET << std::endl;
	else
		std::cout << CYAN << this->_target << " robotomization failed" << RESET << std::endl;
}