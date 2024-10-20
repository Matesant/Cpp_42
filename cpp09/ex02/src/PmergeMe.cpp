# include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

void PmergeMe::parseGood(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (!_validNumber(token))
		{
			printColor("Invalid expression", RED);
			return ;
		}
		_deque.push_back(std::atoi(token.c_str()));
		_list.push_back(std::atoi(token.c_str()));
	}
	_calculateDeque();
	//_calculateList();
}

void PmergeMe::_calculateDeque(void)
{
	
}

void PmergeMe::_calculateList(void)
{
	_list.sort();
	std::list<int>::iterator it = _list.begin();
	while (it != _list.end())
	{
		printColor(*it, GREY);
		++it;
	}
}

bool PmergeMe::_validNumber(const std::string &expression)
{
	std::istringstream iss(expression);
	int l;
	iss >> std::noskipws >> l;
	if (iss.eof() && !iss.fail())
	{
		return true;
	}
	else
	{
		return false;
	}
}