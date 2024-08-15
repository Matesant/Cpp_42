#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>

# include "Weapon.hpp"

// Class declaration
class HumanA
{
  public:
	HumanA(std::string name, Weapon &weapon);
	void attack();

  private:
	std::string name;
	Weapon &weapon;
};

#endif // HUMANA_HPP
