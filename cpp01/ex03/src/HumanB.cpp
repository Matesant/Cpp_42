#include "./includes/Weapon.hpp"
#include "./includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	return ;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack(void)
{
	if (this->_weapon && this->_weapon->getType() != "")
		std::cout << BOLD << GREEN <<  this->_name << BOLD << CYAN <<  " attacks with his " << this->_weapon->getType() << RESET << std::endl;
	else
		std::cout << BOLD << GREEN << this->_name << BOLD << CYAN << " has no weapon to attack with" << RESET << std::endl;
	return ;
}