#include "./includes/Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << CYAN << "Creating a Dog!" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog Destructor called" << RESET << std::endl;
	delete this->_brain;
	this->_brain = NULL;
}

Dog::Dog(const Dog &copy) : Animal(copy), _brain(new Brain(*copy._brain))
{
	std::cout << BOLD << "Dog Copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &rightSide)
{
	Brain	*newBrain;

	std::cout << BOLD << "Dog Assignation operator called" << RESET << std::endl;
	if (this != &rightSide)
	{
		Animal::operator=(rightSide);
		newBrain = new Brain(*rightSide._brain);
		delete this->_brain;
		this->_brain = newBrain;
	}
	return (*this);
}

std::string Dog::getType() const
{
	return (this->_type);
}

std::string Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

void Dog::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

void Dog::makeSound() const
{
	std::cout << GREEN << "BARK BARK BARK!" << RESET << std::endl;
}