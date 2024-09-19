#include "./includes/Cure.hpp"

Cure::Cure() : AMateria("cure") 
{
	std::cout << ORANGE << "Cure constructor" << RESET << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {}

Cure &Cure::operator=(const Cure &rhs)
{
	if (this == &rhs)
		return (*this);
	AMateria::operator=(rhs);
	return (*this);
}

Cure::~Cure()
{
	std::cout << RED << "Cure destructor" << RESET << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << GREEN << "* heals " << target.getName() << "’s wounds *" << RESET << std::endl;
}
