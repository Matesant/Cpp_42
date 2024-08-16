
#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string CYAN = "\033[36m";
const std::string BOLD = "\033[1m";
const std::string BLINK = "\033[5m";
const std::string RESET = "\033[0m";
const std::string YELLOW = "\033[33m";
const std::string INVERSE = "\033[7m";
const std::string BRIGHT_MAGENTA = "\033[95m";


// Class declaration
class Harl
{
  public:
  Harl(void);
  ~Harl(void);
	void complain(std::string level);

  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif
