#include "./includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("NoNameTrap"), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << RESET << BOLD << "A default ClapTrap with no name was created with " 
	<< BOLD_LIME << _hitPoints << RESET << BOLD << " hit points, "
	<< BOLD_PINK << _energyPoints << RESET << BOLD << " energy points and " 
	<< BOLD_RED << _attackDamage << RESET << BOLD << " attack damage" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << RESET << BOLD << "Claptrap " << BOLD_PURPLE << this->_name << RESET << BOLD << " was created with " 
	<< BOLD_LIME << _hitPoints << RESET << BOLD << " hit points, "
	<< BOLD_PINK << _energyPoints << RESET << BOLD << " energy points and " 
	<< BOLD_RED << _attackDamage << RESET << BOLD << " attack damage" << RESET << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BOLD_RED << "Destructor called" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rigthSide)
{
	std::cout << BOLD_BRIGHT_MAGENTA << "Assignation operator called" << RESET << std::endl;
	this->_name = rigthSide._name;
	this->_hitPoints = rigthSide._hitPoints;
	this->_energyPoints = rigthSide._energyPoints;
	this->_attackDamage = rigthSide._attackDamage;
	return (*this);
}

int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

void ClapTrap::attack(std::string const &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << BOLD_YELLOW << "ClapTrap " << BOLD_PURPLE << this->_name 
		<< BOLD_ORANGE << " is dead and cannot attack" << RESET << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << BOLD_YELLOW << "ClapTrap " << BOLD_PURPLE << this->_name 
		<< BOLD_ORANGE << " has no energy points and cannot attack" << RESET << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << BOLD_YELLOW << "ClapTrap " << BOLD_PURPLE << this->_name << BOLD_YELLOW 
	<< " attacks " << BOLD_PURPLE <<target
	<< BOLD_YELLOW << ", causing " << BOLD_RED << this->_attackDamage 
	<< BOLD_YELLOW << " points of damage and now have " << BOLD_PINK 
	<< this->_energyPoints << BOLD_YELLOW 
	<< " energy points" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << BOLD_YELLOW << "ClapTrap " << BOLD_PURPLE 
		<< this->_name << " is already dead" << RESET << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << BOLD_ORANGE << "ClapTrap " << BOLD_PURPLE 
	<< this->_name << BOLD_ORANGE <<" takes " << BOLD_RED 
	<< amount << BOLD_ORANGE << " points of damage and now have " 
	<< BOLD_LIME << this->_hitPoints << BOLD_ORANGE << " hit points" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << BOLD_YELLOW << "ClapTrap " << BOLD_PURPLE 
		<< this->_name << BOLD_ORANGE << " is dead and cannot be repaired" 
		<< RESET << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << BOLD_YELLOW << "ClapTrap " << BOLD_PURPLE 
		<< this->_name << BOLD_ORANGE << " has no energy points and cannot be repaired" 
		<< RESET << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << BOLD_YELLOW << "ClapTrap " << BOLD_PURPLE << this->_name 
	<< BOLD_ORANGE << " is repaired by " << BOLD_BLUE << amount << BOLD_YELLOW 
	<< " points and now have " << BOLD_LIME << this->_hitPoints << BOLD_YELLOW 
	<< " hit points and " << BOLD_PINK << this->_energyPoints << BOLD_YELLOW 
	<< " energy points" << RESET << std::endl;
}