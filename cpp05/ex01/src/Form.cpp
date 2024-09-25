#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << CYAN << "Form Default constructor called" << RESET << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << CYAN << "Creating a form with the name: " << MAGENTA << this->_name << RESET << std::endl;
}

Form::~Form()
{
	std::cout << RED << "Form Destructor called" << RESET << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << BOLD << "Form Copy constructor called" << RESET << std::endl;
}

Form &Form::operator=(Form const &rightSide)
{
	std::cout << BOLD << "Form Assignation operator called" << RESET << std::endl;
	this->_signed = rightSide._signed;
	return (*this);
}

std::string Form::getName(void) const
{
	return (this->_name);
}

bool Form::getSigned(void) const
{
	return (this->_signed);
}

int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (this->_signed)
		throw Form::FormNotSignedException();
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

void Form::execute(Bureaucrat const &executor) const
{
	(void)executor;
	return ;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (MAGENTA "Grade is too low" RESET);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return (MAGENTA "Grade is too high" RESET);
}

const char *Form::FormNotSignedException::what() const throw()
{
	return (MAGENTA "Form is not signed" RESET);
}

std::ostream &operator<<(std::ostream &out, Form const &value)
{
	out << GREEN << "Form " << value.getName() << " needs " << value.getGradeToSign() << " to be signed and is " << (value.getSigned() ? "signed" : "not signed") << RESET;
	return (out);
}