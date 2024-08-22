#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

# include <cctype>
# include <iostream>
# include <string>

const std::string RED = "\033[31m";
const std::string CYAN = "\033[36m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BOLD = "\033[1m";
const std::string BLINK = "\033[5m";
const std::string INVERSE = "\033[7m";
const std::string RESET = "\033[0m";

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
