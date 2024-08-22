
#ifndef BRAIN_HPP_
# define BRAIN_HPP_

# include "./Utils.hpp"

// Class declaration
class Brain
{
  public:
	Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &rightSide);
	~Brain();

	// Getters and setters
	std::string getIdea(int index) const;
	void setIdea(int index, std::string idea);

  private:
	std::string _ideas[100];
};

#endif // BRAIN_HPP_
