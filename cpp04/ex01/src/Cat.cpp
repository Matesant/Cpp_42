#include "./includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << CYAN << "Creating a Cat!" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat Destructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << BOLD << "Cat Copy constructor called" << RESET << std::endl;
	*this = copy;
}

Cat &Cat::operator=(Cat const &rightSide)
{
	std::cout << BOLD << "Cat Assignation operator called" << RESET << std::endl;
	this->_type = rightSide._type;
	return (*this);
}

std::string Cat::getType(void) const
{
	return (this->_type);
}

void Cat::makeSound(void) const
{
	std::cout << GREEN << "MEOOOOW!" << RESET << std::endl;
}