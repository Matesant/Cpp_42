
#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

# include <iostream>
# include <string>
# include <math.h>

const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string CYAN = "\033[1;36m";
const std::string YELLOW = "\033[1;33m";
const std::string MAGENTA = "\033[1;95m";
const std::string BLUE = "\033[1;34m";
const std::string BOLD = "\033[1m";
const std::string RESET = "\033[0m";
const std::string INVERSE = "\033[7m";

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
