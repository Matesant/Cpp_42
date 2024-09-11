#include "./includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std << INVERSE << "New MateriaSource created" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std << INVERSE << "New MateriaSource created by copy" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = other._materia[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	std << INVERSE << "MateriaSource assigned" << RESET << std::endl;
	if (this == &rhs)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
		this->_materia[i] = rhs._materia[i];
	}
	for (int i = 0; i < 4; i++)
		this->_materia[i] = rhs._materia[i];
	return *this;
}
