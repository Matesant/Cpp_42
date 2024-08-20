
#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

# include <iostream>
# include <string>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string CYAN = "\033[36m";
const std::string YELLOW = "\033[33m";
const std::string BRIGHT_MAGENTA = "\033[95m";
const std::string BOLD_RED = "\033[1;31m";
const std::string BOLD_GREEN = "\033[1;32m";
const std::string BOLD_CYAN = "\033[1;36m";
const std::string BOLD_YELLOW = "\033[1;33m";
const std::string BOLD_BRIGHT_MAGENTA = "\033[1;95m";
const std::string BOLD_BLUE = "\033[1;34m";
const std::string BOLD_PINK = "\033[1;35m";
const std::string BOLD_ORANGE = "\033[1;33m";
const std::string BOLD_PURPLE = "\033[1;35m";
const std::string BOLD_LIME = "\033[1;92m";
const std::string BOLD = "\033[1m";
const std::string RESET = "\033[0m";
const std::string INVERSE = "\033[7m";

// Class declaration
class ClapTrap {
 public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &other);
  ~ClapTrap();

  ClapTrap &operator=(const ClapTrap &rigthSide);
  // member functions
  void attack(std::string const & target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  // Getters
  std::string getName(void) const;
  int getAttackDamage(void) const;

 private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
  
};

#endif // CLAPTRAP_HPP_

