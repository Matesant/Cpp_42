
#ifndef CAT_HPP_
# define CAT_HPP_

# include "./Utils.hpp"
# include "./Animal.hpp"


// Class declaration
class Cat: public Animal
{
  public:
	Cat();
	Cat(std::string name);
	Cat(const Cat &other);
	virtual ~Cat();

	Cat &operator=(const Cat &rigthSide);

	// Getters
	std::string getType(void) const;
	virtual void makeSound(void) const;
};

#endif
