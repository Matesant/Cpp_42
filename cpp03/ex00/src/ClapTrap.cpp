#include "./includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("NoNameTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << RESET << BOLD << "A default ClapTrap with no name was created with " << GREEN << _hitPoints << RESET << BOLD << " hit points, "
			  << MAGENTA << _energyPoints << RESET << BOLD << " energy points and " << RED << _attackDamage << RESET << BOLD << " attack damage" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << RESET << BOLD << "Claptrap " << MAGENTA << this->_name << RESET << BOLD << " was created with " << GREEN << _hitPoints << RESET << BOLD << " hit points, "
			  << MAGENTA << _energyPoints << RESET << BOLD << " energy points and " << RED << _attackDamage << RESET << BOLD << " attack damage" << RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap Destructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rightSide)
{
	std::cout << MAGENTA << "Assignation operator called" << RESET << std::endl;
	this->_name = rightSide._name;
	this->_hitPoints = rightSide._hitPoints;
	this->_energyPoints = rightSide._energyPoints;
	this->_attackDamage = rightSide._attackDamage;
	return (*this);
}

int ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << YELLOW << "ClapTrap " << MAGENTA << this->_name << YELLOW << " is dead and cannot attack" << RESET << std::endl;
		return;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << YELLOW << "ClapTrap " << MAGENTA << this->_name << YELLOW << " has no energy points and cannot attack" << RESET << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	std::cout << YELLOW << "ClapTrap " << MAGENTA << this->_name << YELLOW << " attacks " << MAGENTA << target << YELLOW << ", causing " << RED << this->_attackDamage << YELLOW << " points of damage and now has " << MAGENTA << this->_energyPoints << YELLOW << " energy points" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
	{
		std::cout << YELLOW << "ClapTrap " << MAGENTA << this->_name << YELLOW << " is dead" << RESET << std::endl;
		return;
	}
	std::cout << YELLOW << "ClapTrap " << MAGENTA << this->_name << YELLOW << " takes " << RED << amount << YELLOW << " points of damage and now has " << GREEN << this->_hitPoints << YELLOW << " hit points" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << YELLOW << "ClapTrap " << MAGENTA << this->_name << YELLOW << " is dead and cannot be repaired" << RESET << std::endl;
		return;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << YELLOW << "ClapTrap " << MAGENTA << this->_name << YELLOW << " has no energy points and cannot be repaired" << RESET << std::endl;
		return;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << YELLOW << "ClapTrap " << MAGENTA << this->_name << YELLOW << " is repaired by " << BLUE << amount << YELLOW << " points and now has " << GREEN << this->_hitPoints << YELLOW << " hit points and " << MAGENTA << this->_energyPoints << YELLOW << " energy points" << RESET << std::endl;
}
