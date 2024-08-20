#include "./includes/ClapTrap.hpp"

int	main(void)
{
	std::cout << INVERSE << BOLD << "Creating a no name ClapTrap and Jorge" << RESET << std::endl;
	ClapTrap clapTrap;
	ClapTrap clapTrap2("jorge");

	std::cout << INVERSE << BOLD << "Attacking Jorge" << RESET << std::endl;
	clapTrap.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap.getAttackDamage());
	std::cout << INVERSE << BOLD << "Repairing Jorge" << RESET << std::endl;
	clapTrap2.beRepaired(5);
	std::cout << INVERSE << BOLD << "Attacking no name" << RESET << std::endl;
	clapTrap2.attack(clapTrap.getName());
	clapTrap.takeDamage(clapTrap2.getAttackDamage());
	std::cout << INVERSE << BOLD << "Repairing no name" << RESET << std::endl;
	clapTrap.beRepaired(5);
	clapTrap.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap.getAttackDamage());
	clapTrap2.attack(clapTrap.getName());
	clapTrap.takeDamage(clapTrap2.getAttackDamage());
	clapTrap2.beRepaired(5);
	clapTrap.beRepaired(5);
	clapTrap.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap.getAttackDamage());
	clapTrap2.attack(clapTrap.getName());
	clapTrap.takeDamage(clapTrap2.getAttackDamage());
	clapTrap2.beRepaired(5);
	clapTrap.beRepaired(5);
	clapTrap.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap.getAttackDamage());
	clapTrap2.attack(clapTrap.getName());
	clapTrap.takeDamage(clapTrap2.getAttackDamage());
	clapTrap2.beRepaired(5);
	clapTrap.beRepaired(5);
	clapTrap.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap.getAttackDamage());
	clapTrap2.attack(clapTrap.getName());
	clapTrap.takeDamage(clapTrap2.getAttackDamage());
	clapTrap2.beRepaired(5);
	clapTrap.beRepaired(5);
	clapTrap.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap.getAttackDamage());
	clapTrap2.attack(clapTrap.getName());
	clapTrap.takeDamage(clapTrap2.getAttackDamage());
	
	return (0);
}
