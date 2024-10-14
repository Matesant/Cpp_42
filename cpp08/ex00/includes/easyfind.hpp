#ifndef EASYFIND_HPP
# define EASYFIND_HPP

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

# include <cmath>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <string>
# include <unistd.h>
# include <vector>
# include <algorithm>

template <typename T> 
std::string toString(const T &value);

template <typename T> 
void printColor(const T &value, const std::string &color);

template <typename T> 
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(),value);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return (it);
}

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