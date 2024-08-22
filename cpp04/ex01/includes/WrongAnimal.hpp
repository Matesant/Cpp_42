
#ifndef WRONGANIMAL_HPP_
# define WRONGANIMAL_HPP_

# include <iostream>
# include <string>

// Class declaration
class WrongAnimal
{
  public:
	WrongAnimal();
	WrongAnimal(std::string name);
	WrongAnimal(const WrongAnimal &other);
	virtual ~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &rigthSide);

	// Getters
	std::string getType(void) const;
	virtual void makeSound(void) const;

  protected:
	std::string _type;
};

#endif
