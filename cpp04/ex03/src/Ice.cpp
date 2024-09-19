#include "./includes/Ice.hpp"

Ice::Ice() : AMateria("ice") 
{
	std::cout << ORANGE << "Ice constructor" << RESET << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {}

Ice &Ice::operator=(const Ice &rhs)
{
	if (this == &rhs)
		return (*this);
	AMateria::operator=(rhs);
	return (*this);
}

Ice::~Ice()
{
	std::cout << RED << "Ice destructor" << RESET << std::endl;
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
