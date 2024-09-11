#include "./includes/Cure.hpp"

Cure::Cure() : AMateria("cure") 
{
	std::cout << "Cure constructor" << std::endl;
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
	std::cout << "Cure destructor" << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
