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
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void setName(std::string name);
	void announce(void);
};

Zombie	*zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP_
