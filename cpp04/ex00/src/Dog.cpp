#include "./includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << CYAN << BOLD << "Creating a Dog!" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << BOLD << "Dog Destructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << BOLD << "Dog Copy constructor called" << RESET << std::endl;
	*this = copy;
}

Dog &Dog::operator=(Dog const &rightSide)
{
	std::cout << BOLD << "Dog Assignation operator called" << RESET << std::endl;
	this->_type = rightSide._type;
	return (*this);
}

std::string Dog::getType(void) const
{
	return (this->_type);
}

void Dog::makeSound(void) const
{
	std::cout << GREEN << BOLD << "WOOF WOOF!" << RESET << std::endl;
}