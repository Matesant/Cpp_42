
#ifndef DOG_HPP_
# define DOG_HPP_

# include "./Animal.hpp"
# include <iostream>
# include <string>

// Class declaration
class Dog : public Animal
{
  public:
	Dog();
	Dog(std::string name);
	Dog(const Dog &other);
	virtual ~Dog();

	Dog &operator=(const Dog &rigthSide);

	// member functions
	virtual void makeSound(void) const;
	std::string getType(void) const;
};

#endif
