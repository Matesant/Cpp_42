#include "./includes/ScavTrap.hpp"
#include "./includes/FragTrap.hpp"
#include "./includes/DiamondTrap.hpp"

int	main(void)
{
	std::cout << INVERSE << "CREATING CLAPTRAP" << RESET << std::endl;
	ClapTrap ClapTrap1("JUAN");
	std::cout << INVERSE << "CREATING SCAVTRAP" << RESET << std::endl;
	ScavTrap ScavTrap1("CARAMEL");
	std::cout << INVERSE << "CREATING FRAGTRAP" << RESET << std::endl;
	FragTrap FragTrap1("TOKAKI");

	std::cout << INVERSE << "ATTACKING CLAPTRAP" << RESET << std::endl;
	ClapTrap1.attack(ScavTrap1.getName());
	ScavTrap1.takeDamage(ClapTrap1.getAttackDamage());
	ScavTrap1.beRepaired(5);
	ScavTrap1.attack(ClapTrap1.getName());
	ClapTrap1.takeDamage(ScavTrap1.getAttackDamage());
	ClapTrap1.beRepaired(5);
	ClapTrap1.attack(ScavTrap1.getName());
	ScavTrap1.takeDamage(ClapTrap1.getAttackDamage());
	std::cout << INVERSE << "ATTACKING SCAVTRAP" << RESET << std::endl;
	ScavTrap1.attack(FragTrap1.getName());
	FragTrap1.takeDamage(ScavTrap1.getAttackDamage());
	FragTrap1.beRepaired(5);
	FragTrap1.attack(ScavTrap1.getName());
	ScavTrap1.takeDamage(FragTrap1.getAttackDamage());
	ScavTrap1.beRepaired(5);
	ScavTrap1.attack(FragTrap1.getName());
	FragTrap1.takeDamage(ScavTrap1.getAttackDamage());
	std::cout << INVERSE << "ATTACKING FRAGTRAP" << RESET << std::endl;
	FragTrap1.attack(ClapTrap1.getName());
	ClapTrap1.takeDamage(FragTrap1.getAttackDamage());
	ClapTrap1.beRepaired(5);
	ClapTrap1.attack(FragTrap1.getName());
	FragTrap1.takeDamage(ClapTrap1.getAttackDamage());
	ClapTrap1.beRepaired(5);

	std::cout << INVERSE << "WE ARE FRIEND GUYS" << RESET << std::endl;
	ScavTrap1.guardGate();
	FragTrap1.highFivesGuys();

	ClapTrap1.beRepaired(100);
	std::cout << INVERSE << "CREATING DIAMONDTRAP" << RESET << std::endl;
	DiamondTrap DiamondTrap1("DIAMOND");
	std::cout << INVERSE << "DIAMONDTRAP ATTACKING CLAPTRAP" << RESET << std::endl;
	DiamondTrap1.ScavTrap::attack(ClapTrap1.getName());
	ClapTrap1.takeDamage(DiamondTrap1.ScavTrap::getAttackDamage());
	ClapTrap1.beRepaired(5);
	ClapTrap1.attack(DiamondTrap1.ScavTrap::getName());
	DiamondTrap1.ScavTrap::takeDamage(ClapTrap1.getAttackDamage());
	DiamondTrap1.ScavTrap::beRepaired(5);
	DiamondTrap1.ScavTrap::guardGate();
	DiamondTrap1.FragTrap::highFivesGuys();
	DiamondTrap1.whoIAm();





	

	return (0);
}
