#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define ORANGE "\033[1;38;5;208m"
# define PINK "\033[1;38;5;213m"
# define PURPLE "\033[1;38;5;135m"
# define GREY "\033[1;38;5;246m"
# define BROWN "\033[1;38;5;130m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;95m"
# define BLUE "\033[1;34m"
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define INVERSE "\033[7m"
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <algorithm>
# include <cmath>
# include <cstdio>
# include <deque>
# include <iostream>
# include <list>
# include <sstream>
# include <string>
# include <vector>
# include <ctime>
# include <iomanip>

template <typename T> std::string toString(const T &value);

template <typename T> void printColor(const T &value, const std::string &color);

class PmergeMe
{
  private:
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	std::list<int> _list;
	std::deque<int> _deque;
	std::vector<int> _jacobsthalNumbers;
	std::vector<int> _insertion;
	double _elapsedDeque;
	double _elapsedList;

	// methods
	bool _validNumber(const std::string &expression);
	void _divideIntoPairsList(void);

  public:
	PmergeMe(void);
	~PmergeMe(void);
	void mergeInsertDeque(std::deque<int> &mainSet);
	void mergeInsertList(std::list<int> &list);
	void insertPendingElements(std::deque<int> &mainSet,
		std::deque<int> &pendingSet);
	void generateJacobstal(unsigned long n);
	void generateInsertionIndexWithJacobsthal(unsigned long size);
	std::deque<int> createMainAndPendingSet(std::deque<int> &mainSet,
		std::deque<int> &array);
	std::list<int> createMainAndPendingSet(std::list<int> &mainSet,
		std::list<int> &array);
	void insertPendingElements(std::list<int> &mainSet,
		std::list<int> &pendingSet);
	std::list<int>::iterator advanceIterator(std::list<int>::iterator it,
		size_t n);

	void parseGood(int argc, char **argv);
};

template <typename T> std::string toString(const T &value)
{
	std::stringstream ss;
	ss << value;
	return (ss.str());
}

template <typename T> void printColor(const T &value, const std::string &color)
{
	std::cout << color << toString(value) << RESET << ' ';
}

#endif