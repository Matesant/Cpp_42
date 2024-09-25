#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default AForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << CYAN << "AForm Default constructor called" << RESET << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << CYAN << "Creating a form with the name: " << MAGENTA << this->_name << RESET << std::endl;
}

AForm::~AForm()
{
	std::cout << RED << "AForm Destructor called" << RESET << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << BOLD << "AForm Copy constructor called" << RESET << std::endl;
}

AForm &AForm::operator=(AForm const &rightSide)
{
	std::cout << BOLD << "AForm Assignation operator called" << RESET << std::endl;
	this->_signed = rightSide._signed;
	return (*this);
}

std::string AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getSigned(void) const
{
	return (this->_signed);
}

int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (this->_signed)
		throw AForm::FormNotSignedException();
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (MAGENTA "Grade is too low" RESET);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return (MAGENTA "Grade is too high" RESET);
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return (MAGENTA "Form is not signed" RESET);
}

std::ostream &operator<<(std::ostream &out, AForm const &value)
{
	out << GREEN << "Form " << value.getName() << " needs " << value.getGradeToSign() << " to be signed and is " << (value.getSigned() ? "signed" : "not signed") << RESET;
	return (out);
}
