#include "./includes/Zombie.hpp"

int main(void)
{
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BOLD << CYAN << "Testing Allocation in Heap with New" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BOLD << CYAN << "Creating Reginaldo, the first of his kind" << RESET << std::endl;
	Zombie *zombie = newZombie("Reginaldo");
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BOLD << CYAN << "Announcing Reginaldo" << RESET << std::endl;
	zombie->announce();
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BOLD << CYAN << "Goodbye Reginaldo" << RESET << std::endl;
	delete zombie;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;

	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BOLD << CYAN << "Testing Allocation in Stack" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BOLD << CYAN << "Creating Jorge, the second of his kind" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	Zombie zombie2("Jorge");
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BOLD << CYAN << "Announcing Jorge" << RESET << std::endl;
	zombie2.announce();
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BOLD << CYAN << "Goodbye Jorge" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BOLD << CYAN << "Testing Allocation in Stack with the function" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BOLD << CYAN << "Creating Sabrino the zombie that (re)died too fast" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;

	randomChump("Sabrino");
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;
	std::cout << BOLD << CYAN << "Goodbye Sabrino" << RESET << std::endl;
	std::cout << BLINK << RED << "-----------------------------------------------" << RESET << std::endl;

	return (0);
}