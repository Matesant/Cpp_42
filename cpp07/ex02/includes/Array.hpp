#ifndef ARRAY_HPP
# define ARRAY_HPP

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
# include <string>
# include <sstream>
# include <iostream>
# include <stdexcept>

template <typename T>
std::string toString(const T& value);

template <typename T>
void printColor(const T& value, const std::string& color);

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;

	public:
		// Default constructor with no size
		Array() : _array(NULL), _size(0) {};

		// Constructor if size is given
		Array(unsigned int n) : _array(new T[n]), _size(n) {};
		
		// Copy constructor
		Array(const Array &other)
		{
			this->_array = new T[other._size];
			for (unsigned int i = 0; i < other._size; i++)
				this->_array[i] = other._array[i];
			this->_size = other._size;
		}

		// Destructor
		~Array()
		{
			if (this->_array)
				delete[] this->_array;
		}

		// Assignation operator
		Array& operator=(const Array& other)
		{
			if (this == &other)
				return *this;
			if (this->_array)
				delete[] this->_array;
			this->_array = new T[other._size];
			for (unsigned int i = 0; i < other._size; i++)
				this->_array[i] = other._array[i];
			this->_size = other._size;
			return *this;
		}

		// Overload operator [] to access elements
		T& operator[](unsigned int index)
		{
			if (index >= this->_size)
				throw std::out_of_range("Index out of range");
			return this->_array[index];
		}

		// Overload operator [] to access elements
		const T& operator[](unsigned int index) const
		{
			if (index >= this->_size)
				throw std::out_of_range("Index out of range");
			return this->_array[index];
		}

		// Return the size of the array
		unsigned int size() const
		{
			return this->_size;
		}

		class OutOfLimitsException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Index out of limits";
				}
		};
};

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