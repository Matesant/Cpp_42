#include "./includes/Brain.hpp"

Brain::Brain()
{
	std::cout << CYAN << "Creating Ideas!" << RESET << std::endl;
	std::string ideas[8] = {
		"EAT EVERYTHING",
		"SLEEP ALL DAY",
		"RUN AWAY",
		"PLAY DEAD",
		"DOMINATE WORLD",
		"DESTROY HUMANS",
	};
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideas[rand() % 6];
}

Brain::~Brain()
{
	std::cout << RED << "Brain Destructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << BOLD << "Brain Copy constructor called" << RESET << std::endl;
	*this = copy;
}

Brain &Brain::operator=(Brain const &rightSide)
{
	std::cout << BOLD << "Brain Assignation operator called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rightSide._ideas[i];
	return (*this);
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index > 100)
		return ("TDH ENTERED THE CHAT");
	return (this->_ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index > 100)
		return ;
	this->_ideas[index] = idea;
}
