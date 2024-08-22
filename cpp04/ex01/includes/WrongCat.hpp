
#ifndef WRONGCAT_HPP_
# define WRONGCAT_HPP_

# include "./WrongAnimal.hpp"
# include <iostream>
# include <string>

// Class declaration
class WrongCat : public WrongAnimal
{
  public:
	WrongCat();
	WrongCat(std::string name);
	WrongCat(const WrongCat &other);
	virtual ~WrongCat();

	WrongCat &operator=(const WrongCat &rigthSide);

	// Getters
	std::string getType(void) const;
	virtual void makeSound(void) const;

  protected:
	std::string _type;
};

#endif
