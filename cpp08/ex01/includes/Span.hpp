#ifndef SPAN_HPP
# define SPAN_HPP

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

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v;
	public:
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		void addNumber(int number);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan(void);
		int longestSpan(void);

		class tooManySpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class fullSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class noSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class notEnoughNumbersException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif