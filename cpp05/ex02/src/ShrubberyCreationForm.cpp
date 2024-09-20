# include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << CYAN << "ShrubberyCreationForm constructor called" << RESET << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	std::cout << CYAN << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << CYAN << "ShrubberyCreationForm assignation operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << CYAN << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");
	file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
	file.close();
}