#include "./includes/HumanA.hpp"
#include "./includes/HumanB.hpp"
#include "./includes/Weapon.hpp"

int	main(void)
{
	{
		std::cout << BOLD << INVERSE << "CREATING WEAPON TYPE 'CLUB' FOR HUMAN_A" << RESET << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		std::cout << BOLD << RED << "BOB ATTACKS" << RESET << std::endl;
		bob.attack();
		std::cout << BOLD << INVERSE << "CHANGING WEAPON TYPE TO 'SOME OTHER TYPE OF CLUB'" << RESET << std::endl;
		club.setType("some other type of club");
		std::cout << BOLD << RED << "BOB ATTACKS" << RESET << std::endl;
		bob.attack();
	}
	{
		std::cout << BOLD << INVERSE << "CREATING WEAPON TYPE 'CLUB' FOR HUMAN_B" << RESET << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		std::cout << BOLD << RED << "JIM ATTACKS WITH NO WEAPON" << RESET << std::endl;
		jim.attack();
		std::cout << BOLD << INVERSE << "GIVING JIM A WEAPON" << RESET << std::endl;
		jim.setWeapon(club);
		std::cout << BOLD << RED << "JIM ATTACKS" << RESET << std::endl;
		jim.attack();
		std::cout << BOLD << INVERSE << "CHANGING WEAPON TYPE TO 'SOME OTHER TYPE OF CLUB'" << RESET << std::endl;
		club.setType("some other type of club");
		std::cout << BOLD << RED << "JIM ATTACKS" << RESET << std::endl;
		jim.attack();
	}
}