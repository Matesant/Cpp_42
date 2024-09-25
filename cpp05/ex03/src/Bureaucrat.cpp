#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default")
{
	this->_grade = 99;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << INVERSE << CYAN << "Bureaucrat " << _name << " created" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << INVERSE << CYAN << "Bureaucrat " << _name << " created" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name),
	_grade(other._grade)
{
	std::cout << BOLD << "Bureaucrat " << _name << " created by copy" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << INVERSE << RED << "Bureaucrat " << _name << " destroyed" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rigthSide)
{
	if (this != &rigthSide)
		this->_grade = rigthSide._grade;
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (MAGENTA "Grade is too high" RESET);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (MAGENTA "Grade is too low" RESET);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &value)
{
	out << GREEN << value.getName() << ", bureaucrat grade " << value.getGrade() << RESET;
	return (out);
}

void Bureaucrat::signForm(AForm &AForm)
{
	try
	{
		AForm.beSigned(*this);
		std::cout << GREEN << this->getName() << " signs " << AForm.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << this->getName() << " cannot sign " << AForm.getName() << " because " << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &AForm)
{
	AForm.execute(*this);
}
