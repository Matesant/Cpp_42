#include "./includes/Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	std::cout << CYAN << "Creating a Cat!" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat Destructor called" << RESET << std::endl;
	delete this->_brain;
	this->_brain = NULL;
}

Cat::Cat(const Cat &copy) : Animal(copy), _brain(new Brain(*copy._brain))
{
	std::cout << BOLD << "Cat Copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &rightSide)
{
	Brain	*newBrain;

	std::cout << BOLD << "Cat Assignation operator called" << RESET << std::endl;
	if (this != &rightSide)
	{
		Animal::operator=(rightSide);
		newBrain = new Brain(*rightSide._brain);
		delete this->_brain;
		this->_brain = newBrain;
	}
	return (*this);
}

std::string Cat::getType() const
{
	return (this->_type);
}

std::string Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

void Cat::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

void Cat::makeSound() const
{
	std::cout << GREEN << "MEOOOOW!" << RESET << std::endl;
}