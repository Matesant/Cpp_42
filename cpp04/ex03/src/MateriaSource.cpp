#include "./includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << ORANGE << "New MateriaSource created" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << INVERSE << BOLD << "New MateriaSource created by copy" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = other._materia[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	std::cout << INVERSE << BOLD << "MateriaSource assigned" << RESET << std::endl;
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

MateriaSource::~MateriaSource()
{
	std::cout << RED << "MateriaSource destroyed" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
		this->_materia[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = m;
			std::cout << INVERSE << BOLD << "Materia learned" << RESET << std::endl;
			return;
		}
	}
	std::cout << INVERSE << BOLD << "MateriaSource is full" << RESET << std::endl;
	if (m)
		delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
		{
			std::cout << INVERSE << BOLD << "Materia created" << RESET << std::endl;
			return this->_materia[i]->clone();
		}
	}
	std::cout << INVERSE << BOLD << "Materia not found" << RESET << std::endl;
	return NULL;
}