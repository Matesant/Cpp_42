#ifndef SPAN_HPP
# define SPAN_HPP

#define MAX_INT 2147483647
# include "templates.tpp"

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
		void addNumbersAndFill(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan(void);
		int longestSpan(void);
		std::vector<int> getNumbers(void);

		class tooManyNumberSpanException : public std::exception
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