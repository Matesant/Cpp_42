
#ifndef WRONGCAT_HPP_
# define WRONGCAT_HPP_

# include "./WrongAnimal.hpp"

// Class declaration
class WrongCat: public WrongAnimal
{
  public:
	WrongCat();
	WrongCat(std::string name);
	WrongCat(const WrongCat &other);
	~WrongCat();

	WrongCat &operator=(const WrongCat &rigthSide);

	// Getters
	std::string getType(void) const;
	void makeSound(void) const;
};

#endif
