
#ifndef AANIMAL_HPP_
# define AANIMAL_HPP_

# include "./Utils.hpp"

// Class declaration
class AAnimal
{
  public:
	AAnimal();
	AAnimal(std::string name);
	AAnimal(const AAnimal &other);
	virtual ~AAnimal();

	AAnimal &operator=(const AAnimal &rigthSide);

	// Getters
	std::string getType(void) const;

	// Member functions
	virtual void makeSound(void) const = 0;

  protected:
	std::string _type;
};

#endif
