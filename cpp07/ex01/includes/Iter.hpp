#ifndef ITER_HPP
# define ITER_HPP

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
# include <cmath>
# include <ctime>

template <typename T>
void Iter(T* array, size_t length, void (*func)(T const &))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
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

template <typename T>
void printColorOrange(const T& value)
{
    std::cout << ORANGE << toString(value) << RESET << std::endl;
}

#endif