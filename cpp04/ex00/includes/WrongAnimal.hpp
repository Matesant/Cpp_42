
#ifndef WRONGANIMAL_HPP_
# define WRONGANIMAL_HPP_

# include "./Utils.hpp"

// Class declaration
class WrongAnimal
{
  public:
	WrongAnimal();
	WrongAnimal(std::string name);
	WrongAnimal(const WrongAnimal &other);
	~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &rigthSide);

	// Getters
	std::string getType(void) const;
	void makeSound(void) const;

  protected:
	std::string _type;
};

#endif
