
#ifndef DOG_HPP_
# define DOG_HPP_

# include "./Animal.hpp"
# include "./Brain.hpp"

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
	std::string getIdea(int index) const;
	void setIdea(int index, std::string idea);

  private:
	Brain *_brain;
};

#endif
