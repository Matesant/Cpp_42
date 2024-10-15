#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_n = other._n;
		_v = other._v;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_v.size() >= _n)
		throw fullSpanException();
	_v.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) > _n)
		throw fullSpanException();
	_v.insert(_v.end(), begin, end);
}

int Span::shortestSpan(void)
{
	if (_v.size() <= 1)
		throw notEnoughNumbersException();
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	int min = MAX_INT;
	for (size_t i = 1; i < v.size(); i++)
	{
		if (v[i] - v[i - 1] < min)
			min = v[i] - v[i - 1];
	}
	return min;
}

int Span::longestSpan(void)
{
	if (_v.size() <= 1)
		throw notEnoughNumbersException();
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	return v.back() - v.front();
}

const char *Span::tooManyNumberSpanException::what() const throw()
{
	return "Too many numbers in the constructor";
}

const char *Span::fullSpanException::what() const throw()
{
	return "The span is full";
}

const char *Span::noSpanException::what() const throw()
{
	return "There is no span to calculate";
}

const char *Span::notEnoughNumbersException::what() const throw()
{
	return "There are not enough numbers to calculate the span";
}

std:: vector<int> Span::getNumbers(void)
{
	return _v;
}