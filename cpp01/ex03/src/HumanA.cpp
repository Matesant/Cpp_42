#include "./includes/Weapon.hpp"
#include "./includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	return ;
}

void	HumanA::attack(void)
{
	std::cout << BOLD << GREEN << this->name << BOLD << CYAN << " attacks with his " << this->weapon.getType() << RESET << std::endl;
	return ;
}