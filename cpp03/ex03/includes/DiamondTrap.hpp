
#ifndef DIAMONDTRAP_HPP_
# define DIAMONDTRAP_HPP_

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
  public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap &operator=(const DiamondTrap &rigthSide);
	~DiamondTrap();

	void whoIAm(void);

  private:
	std::string _name;
};

#endif
