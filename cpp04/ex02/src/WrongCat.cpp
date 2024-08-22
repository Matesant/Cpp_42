#include "./includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << CYAN << "Creating a WrongCat!" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat Destructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << BOLD << "WrongCat Copy constructor called" << RESET << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const &rightSide)
{
	std::cout << BOLD << "WrongCat Assignation operator called" << RESET << std::endl;
	this->_type = rightSide._type;
	return (*this);
}

std::string WrongCat::getType(void) const
{
	return (this->_type);
}

void WrongCat::makeSound(void) const
{
	std::cout << GREEN << "MEAU AU AU AU ME AU AU COFF COFF" << RESET << std::endl;
}