#include "./includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Human")
{
	std::cout << CYAN << "WrongAnimal Default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : _type(name)
{
	std::cout << CYAN << "Creating a animal from the type: " << MAGENTA << this->_type << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal Destructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << BOLD << "WrongAnimal Copy constructor called" << RESET << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rightSide)
{
	std::cout << BOLD << "WrongAnimal Assignation operator called" << RESET << std::endl;
	this->_type = rightSide._type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << GREEN << "WrongAnimal says Hello" << RESET << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}