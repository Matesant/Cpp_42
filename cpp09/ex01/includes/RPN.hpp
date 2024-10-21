#ifndef RPN_HPP
# define RPN_HPP

# define ORANGE "\033[38;5;208m"
# define PINK "\033[38;5;213m"
# define PURPLE "\033[38;5;135m"
# define GREY "\033[38;5;246m"
# define BROWN "\033[38;5;130m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;95m"
# define BLUE "\033[1;34m"
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define INVERSE "\033[7m"

# include <algorithm>
# include <cmath>
# include <cstdio>
# include <sstream>
# include <stack>
# include <string>
# include <iostream>

template <typename T> std::string toString(const T &value);

template <typename T> void printColor(const T &value, const std::string &color);

class RPN
{
  private:
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);

	// RPN methods
	bool _isOperator(const std::string &token);
	double _applyTheMathematics(double operand1, double operand2,
		const std::string &token);

	// input validation methods
	bool _validExpression(const std::string &expression);

  public:
	RPN(void);
	~RPN(void);

	void calculate(const std::string &expression);
};

template <typename T> std::string toString(const T &value)
{
	std::stringstream ss;
	ss << value;
	return (ss.str());
}

template <typename T> void printColor(const T &value, const std::string &color)
{
	std::cout << color << toString(value) << RESET << std::endl;
}

#endif