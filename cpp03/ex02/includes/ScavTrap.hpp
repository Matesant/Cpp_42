#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

// Class declaration
class ScavTrap : public ClapTrap
{
  public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &rigthSide);
	// member functions
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void guardGate();

	// Getters
	std::string getName(void) const;
	int getAttackDamage(void) const;
};

#endif
