#include "./includes/FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << RESET << BOLD << "Creating a FragTrap from a ClapTrap with no name with " 
	<< GREEN << this->_hitPoints << RESET << BOLD << " hit points, "
	<< MAGENTA << this->_energyPoints << RESET << BOLD << " energy points and " 
	<< RED << this->_attackDamage << RESET << BOLD << " attack damage" << RESET << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << RESET << BOLD << "FragTrap " << MAGENTA << this->_name << RESET << BOLD << " was created from a ClapTrap with "
			  << GREEN << _hitPoints << RESET << BOLD << " hit points, "
			  << MAGENTA << _energyPoints << RESET << BOLD << " energy points and "
			  << RED << _attackDamage << RESET << BOLD << " attack damage" << RESET << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << RED << "FragTrap Destructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) 
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    *this = copy;
}

FragTrap &FragTrap::operator=(FragTrap const &rightSide)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
    if (this != &rightSide) {
        ClapTrap::operator=(rightSide);
        this->_name = rightSide._name;
        this->_hitPoints = rightSide._hitPoints;
        this->_energyPoints = rightSide._energyPoints;
        this->_attackDamage = rightSide._attackDamage;
    }
    return *this;
}

int FragTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

std::string FragTrap::getName(void) const
{
	return (this->_name);
}

void FragTrap::attack(std::string const &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << YELLOW << "FragTrap " << MAGENTA << this->_name
				  << YELLOW << " is dead and cannot attack" << RESET << std::endl;
		return;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << YELLOW << "FragTrap " << MAGENTA << this->_name
				  << YELLOW << " has no energy points and cannot attack" << RESET << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	std::cout << YELLOW << "FragTrap " << MAGENTA << this->_name << YELLOW
			  << " attacks " << MAGENTA << target
			  << YELLOW << ", causing " << RED << this->_attackDamage
			  << YELLOW << " points of damage and now have " << MAGENTA
			  << this->_energyPoints << YELLOW
			  << " energy points" << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << YELLOW << "FragTrap " << MAGENTA << this->_name
			  << YELLOW << " requests a high five" << RESET << std::endl;
}