#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

# include "Colors.hpp"
# include <cctype>

// Class declaration
class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif // ZOMBIE_HPP_
