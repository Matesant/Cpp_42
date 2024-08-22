
#ifndef CAT_HPP_
# define CAT_HPP_

# include "./Brain.hpp"
# include "./Animal.hpp"

// Class declaration
class Cat : public Animal
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
	std::string getIdea(int index) const;
	void setIdea(int index, std::string idea);

  private:
	Brain *_brain;
};

#endif
