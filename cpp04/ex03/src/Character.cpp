# include "./includes/Character.hpp"

Character::Character() : _name("default")
{
		std::cout << INVERSE << YELLOW << "New character of name " << MAGENTA << "Default" << YELLOW << " has been created!" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::Character(std::string const &name) : _name(name)
{
	std::cout << INVERSE << YELLOW << "New character of name " << MAGENTA << name << YELLOW << " has been created!" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::Character(const Character &other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
	for (int i = 0; i < 4; i++)
		if (other._materia[i])
			_materia[i] = other._materia[i];
}

Character &Character::operator=(const Character &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_name = rhs._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
		_materia[i] = rhs._materia[i] ? rhs._materia[i]->clone() : NULL;

	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i])
			delete _materia[i];
		this->_materia[i] = NULL;
	}
	std::cout << "Character destructor" << std::endl;
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!_materia[i])
		{
			_materia[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_materia[idx])
		return ;
	_materia[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !_materia[idx])
		return ;
	_materia[idx]->use(target);
}
