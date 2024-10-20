# include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
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
	std::deque<int> deque;
	std::list<int> list;

	while (iss >> token)
	{
		if (!_validNumber(token))
		{
			printColor("Invalid expression", RED);
			return ;
		}
		deque.push_back(std::atoi(token.c_str()));
		list.push_back(std::atoi(token.c_str()));
	}
	//print expression before sorting
	std::cout << ORANGE << "Before: ";
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it)
	{
		printColor(*it, ORANGE);
	}
	std::cout << std::endl;
	mergeInsertDeque(deque);
	mergeInsertList(list);
	std::cout << GREY << "After: ";
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it)
	{
		printColor(*it, GREY);
	}
	std::cout << std::endl;

	std::cout << YELLOW << "After: ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		printColor(*it, YELLOW);
	}
	std::cout << std::endl;
}

void PmergeMe::mergeInsertDeque(std::deque<int> &deque)
{
    size_t size = deque.size();
    if (size <= 1)
        return ;

    std::deque<int> mainSet, pendingNumberSet;
    for (size_t i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            mainSet.push_back(std::max(deque[i], deque[i + 1]));
            pendingNumberSet.push_back(std::min(deque[i], deque[i + 1]));
        }
        else
        {
            mainSet.push_back(deque[i]);
        }
    }
    mergeInsertDeque(mainSet);
    
    int firstLargerElement = mainSet[0];
    int smallerElement = -1;

    for (size_t i = 0; i < size; i++)
    {
        if (i + 1 < size)
        {
            if (deque[i] == firstLargerElement || deque[i + 1] == firstLargerElement)
            {
                smallerElement = std::min(deque[i], deque[i + 1]);
                break;
            }
        }
    }
    deque.clear();
    deque = mainSet;

    if (smallerElement != -1 && std::find(deque.begin(), deque.end(), smallerElement) == deque.end())
        deque.push_front(smallerElement);

    for (size_t i = 0; i < pendingNumberSet.size(); i++)
    {
        size_t size2 = deque.size();
        if (pendingNumberSet[i] != smallerElement || size2 == (size - 1))
        {
            std::deque<int>::iterator it = std::lower_bound(deque.begin(), deque.end(), pendingNumberSet[i]);
            deque.insert(it, pendingNumberSet[i]);
        }
    }
}

void PmergeMe::mergeInsertList(std::list<int> &list)
{
    size_t size = list.size();
    if (size <= 1)
        return;

    std::list<int> mainSet, pendingNumberSet;
    std::list<int>::iterator it = list.begin();
    for (size_t i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            int first = *it++;
            int second = *it++;
            mainSet.push_back(std::max(first, second));
            pendingNumberSet.push_back(std::min(first, second));
        }
        else
        {
            mainSet.push_back(*it++);
        }
    }
    mergeInsertList(mainSet);

    int firstLargerElement = mainSet.front();
    int smallerElement = -1;

    it = list.begin();
    for (size_t i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            int first = *it++;
            int second = *it++;
            if (first == firstLargerElement || second == firstLargerElement)
            {
                smallerElement = std::min(first, second);
                break;
            }
        }
    }
    list.clear();
    list = mainSet;

    if (smallerElement != -1 && std::find(list.begin(), list.end(), smallerElement) == list.end())
        list.push_front(smallerElement);

    for (std::list<int>::iterator it = pendingNumberSet.begin(); it != pendingNumberSet.end(); ++it)
    {
        if (*it != smallerElement || list.size() == (size - 1))
        {
            std::list<int>::iterator pos = std::lower_bound(list.begin(), list.end(), *it);
            list.insert(pos, *it);
        }
    }
}

bool PmergeMe::_validNumber(const std::string &expression)
{
    std::istringstream iss(expression);
    long long l;
    iss >> std::noskipws >> l;
    if (iss.eof() && !iss.fail() && l <= MAX_INT && l >= MIN_INT)
    {
        return true;
    }
    else
    {
        return false;
    }
}
