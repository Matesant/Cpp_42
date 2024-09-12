#include "./includes/AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	std::cout << "A new Materia of type default has been created" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "A new Materia of type " << type << " has been created" << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	if (this == &rhs)
		return (*this);
	_type = rhs._type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << RED << "AMateria destructor" << RESET << std::endl;
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
