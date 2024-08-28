#include "./includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << RESET << BOLD << "Creating a ScavTrap from a ClapTrap with no name with " 
	<< GREEN << this->_hitPoints << RESET << BOLD << " hit points, "
	<< MAGENTA << this->_energyPoints << RESET << BOLD << " energy points and " 
	<< RED << this->_attackDamage << RESET << BOLD << " attack damage" << RESET << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << RESET << BOLD << "ScavTrap " << MAGENTA << this->_name << RESET << BOLD << " was created from a ClapTrap with "
			  << GREEN << _hitPoints << RESET << BOLD << " hit points, "
			  << MAGENTA << _energyPoints << RESET << BOLD << " energy points and "
			  << RED << _attackDamage << RESET << BOLD << " attack damage" << RESET << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << RED << "ScavTrap Destructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) 
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    *this = copy;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rightSide)
{
	std::cout << "Assignation operator called" << std::endl;
    if (this != &rightSide) {
        ClapTrap::operator=(rightSide);
        this->_name = rightSide._name;
        this->_hitPoints = rightSide._hitPoints;
        this->_energyPoints = rightSide._energyPoints;
        this->_attackDamage = rightSide._attackDamage;
    }
    return *this;
}

int ScavTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

std::string ScavTrap::getName(void) const
{
	return (this->_name);
}

void ScavTrap::attack(std::string const &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << YELLOW << "ScavTrap " << MAGENTA << this->_name
				  << YELLOW << " is dead and cannot attack" << RESET << std::endl;
		return;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << YELLOW << "ScavTrap " << MAGENTA << this->_name
				  << YELLOW << " has no energy points and cannot attack" << RESET << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	std::cout << YELLOW << "ScavTrap " << MAGENTA << this->_name << YELLOW
			  << " attacks " << MAGENTA << target
			  << YELLOW << ", causing " << RED << this->_attackDamage
			  << YELLOW << " points of damage and now have " << MAGENTA
			  << this->_energyPoints << YELLOW
			  << " energy points" << RESET << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << YELLOW << "ScavTrap " << MAGENTA << this->_name
			  << YELLOW << " has entered in Gate keeper mode" << RESET << std::endl;
}