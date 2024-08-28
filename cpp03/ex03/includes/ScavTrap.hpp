#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

// Class declaration
class ScavTrap : virtual public ClapTrap
{
  public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &rightSide);
	// member functions
	void attack(std::string const &target);
	void guardGate();

	// Getters
	std::string getName(void) const;
	int getAttackDamage(void) const;
};

#endif
