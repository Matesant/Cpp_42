#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << CYAN << "Intern constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << CYAN << "Intern copy constructor called" << RESET << std::endl;
	*this = other;
}

Intern &Intern::operator=(const Intern &rhs)
{
	std::cout << CYAN << "Intern assignation operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		(void)rhs;
	}
	return (*this);
}

Intern::~Intern()
{
	std::cout << CYAN << "Intern destructor called" << RESET << std::endl;
}

AForm* Intern::createShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    AForm *form = NULL;

    std::string Forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm* (Intern::*formCreators[3])(std::string) = {
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm,
        &Intern::createShrubberyCreationForm
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == Forms[i])
        {
            form = (this->*formCreators[i])(target);
            std::cout << GREEN << "Intern creates " << formName << " form" << RESET << std::endl;
            return form;
        }
    }

    std::cout << RED << "Intern cannot create form: " << formName << RESET << std::endl;
    return NULL;
}