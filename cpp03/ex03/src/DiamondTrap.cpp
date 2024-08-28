#include "./includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("noName_clap_name"), ScavTrap(), FragTrap()
{
	_name = "noName";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << INVERSE << CYAN << "DiamondTrap " << MAGENTA 
	<< _name << CYAN << " is born as a hybrid of ClapTrap, ScavTrap, and FragTrap" 
	<< " with " << GREEN << _hitPoints << CYAN << " hit points, " << MAGENTA 
	<< _energyPoints << CYAN << " energy points, and " << RED << _attackDamage 
	<< CYAN << " attack damage"
	<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << INVERSE << CYAN << "DiamondTrap " << MAGENTA << _name << CYAN 
	<< " is born as a hybrid of ClapTrap, ScavTrap, and FragTrap" 
	<< " with " << GREEN << _hitPoints << CYAN << " hit points, " 
	<< MAGENTA << _energyPoints << CYAN << " energy points, and " 
	<< RED << _attackDamage << CYAN << " attack damage"
	<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << YELLOW << _name << " DiamondTrap Copy assignment called" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << _name << " DiamondTrap destructor called" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rightSide)
{
	_name = rightSide._name;
	_hitPoints = rightSide._hitPoints;
	_energyPoints = rightSide._energyPoints;
	_attackDamage = rightSide._attackDamage;
	return (*this);
}

void DiamondTrap::whoIAm(void)
{
	std::cout << INVERSE << CYAN << "DiamondTrap " << MAGENTA << _name << CYAN
	<< " is a hybrid of ClapTrap, ScavTrap, and FragTrap" << RESET << std::endl;
	std::cout << INVERSE << CYAN << "ClapTrap " << MAGENTA 
	<< ClapTrap::_name << CYAN << " is a parent class" << RESET << std::endl;
}
