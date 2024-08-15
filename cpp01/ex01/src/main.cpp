#include "./includes/Zombie.hpp"

int main(void)
{
	int i;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << CYAN << "Creating A Horde of ZOMBIES!!!!!!!!" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	Zombie *zombie;
	zombie = zombieHorde(10, "fabio");
	std::cout << INVERSE << CYAN << "CALLING THE HORDE!!!" << RESET << std::endl;
	for (i = 0; i < 10; i++)
		zombie->announce();
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << CYAN << "RICK GRIMES IS HERE TO SAVE THE DAY!!!" << RESET << std::endl;
	delete[] zombie;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	return (0);
}