#ifndef WHATEVER_HPP
# define WHATEVER_HPP

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

# include <iostream>
# include <string>
# include <sstream>

template <typename T> void swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T min(T a, T b)
{
	if (a == b)
		return (b);
	return (a < b ? a : b);
}

template <typename T> T max(T a, T b)
{
	if (a == b)
		return (b);
	return (a > b ? a : b);
}

template <typename T>
std::string toString(const T& value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

template <typename T>
void printColor(const T& value, const std::string& color)
{
    std::cout << color << toString(value) << RESET << std::endl;
}


#endif