#include "./includes/Animal.hpp"

Animal::Animal() : _type("DogCat")
{
	std::cout << CYAN << "Animal Default constructor called" << RESET << std::endl;
}

Animal::Animal(std::string name) : _type(name)
{
	std::cout << CYAN << "Creating a animal from the type: " << MAGENTA << this->_type << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << RED << "Animal Destructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << BOLD << "Animal Copy constructor called" << RESET << std::endl;
	*this = copy;
}

Animal &Animal::operator=(Animal const &rightSide)
{
	std::cout << BOLD << "Animal Assignation operator called" << RESET << std::endl;
	this->_type = rightSide._type;
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << GREEN << "Randon Animal grunts" << RESET << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}