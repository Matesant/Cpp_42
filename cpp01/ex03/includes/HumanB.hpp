#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>

# include "Weapon.hpp"

// Class declaration
class HumanB
{
  public:
	HumanB(std::string name);
	void attack();
	void setWeapon(Weapon &weapon);

  private:
	std::string _name;
	Weapon *_weapon;
};

#endif // HUMANB_HPP
