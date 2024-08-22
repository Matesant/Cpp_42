
#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

# include "./Utils.hpp"

// Class declaration
class Animal
{
  public:
	Animal();
	Animal(std::string name);
	Animal(const Animal &other);
	virtual ~Animal();

	Animal &operator=(const Animal &rigthSide);

	// Getters
	std::string getType(void) const;

	// Member functions
	virtual void makeSound(void) const;

  protected:
	std::string _type;
};

#endif
