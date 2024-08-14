#include "./includes/Zombie.hpp"

int main(void)
{
	int i;
	
	std::cout << "Creating a new zombie on the heap with newZombie(\"heapZombie\")" << std::endl;
	Zombie *zombie;
	zombie = zombieHorde(10, "fabio");
	for (i = 0; i < 10; i++)
		zombie->announce();
	delete[] zombie;
	return (0);
}