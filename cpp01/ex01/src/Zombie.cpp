#include "./includes/Zombie.hpp"

Zombie::Zombie()
{
    std::cout << GREEN << "A new Zombie is alive (or not)" << RESET << std::endl;
}
void Zombie::announce(void)
{
	std::cout << BOLD << GREEN << this->_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << BOLD << YELLOW << this->_name << " Arose from the tomb and started dancing!" << RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << BOLD << RED << this->_name << " Returned to the tomb!" << RESET << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}