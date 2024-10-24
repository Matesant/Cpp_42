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

void PmergeMe::parseGood(int argc, char **argv)
{
    std::deque<int> deque;
    std::list<int> list;

    for (int i = 1; i < argc; ++i)
    {
        std::string token = argv[i];
        if (!_validNumber(token))
        {
            printColor("Invalid expression", RED);
            std::cout << std::endl;
            return;
        }
        deque.push_back(std::atoi(token.c_str()));
        list.push_back(std::atoi(token.c_str()));
    }
    std::cout << ORANGE << "Before: ";
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it)
    {
        printColor(*it, ORANGE);
    }
    std::cout << std::endl;

    mergeInsertDeque(deque);
    mergeInsertList(list);

    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << GREY << "Elapsed time for deque: " << _elapsedDeque << "s" << std::endl;
    std::cout << YELLOW << "Elapsed time for list: " << _elapsedList << "s" << RESET << std::endl;
}

void PmergeMe::mergeInsertDeque(std::deque<int> &array)
{
        std::deque<int> mainSet, pendingSet;

        clock_t start = clock();
        pendingSet = createMainAndPendingSet(mainSet, array);

        insertPendingElements(mainSet, pendingSet);
        clock_t end = clock();
        _elapsedDeque = double(end - start) / CLOCKS_PER_SEC;
        std::cout << GREY << "After:  ";
        for (std::deque<int>::iterator it = mainSet.begin(); it != mainSet.end(); ++it)
        {
            printColor(*it, GREY);
        }
        std::cout << std::endl;
}

std::deque<int> PmergeMe::createMainAndPendingSet(std::deque<int> &mainSet, std::deque<int> &array)
{
    size_t size = array.size();
    std::deque<int> pendingSet;

    if (size <= 1)
        return pendingSet;

    for (size_t i = 0; i < size; i += 2) 
    {
        if (i + 1 < size) 
        {
            int maxVal = std::max(array[i], array[i + 1]);
            int minVal = std::min(array[i], array[i + 1]);

            std::deque<int>::iterator mainPos = std::upper_bound(mainSet.begin(), mainSet.end(), maxVal);
            mainSet.insert(mainPos, maxVal);

            std::deque<int>::iterator pendingPos = std::upper_bound(pendingSet.begin(), pendingSet.end(), minVal);
            pendingSet.insert(pendingPos, minVal);
        } 
        else 
        {
            std::deque<int>::iterator mainPos = std::upper_bound(mainSet.begin(), mainSet.end(), array[i]);
            mainSet.insert(mainPos, array[i]);
        }
    }

    return pendingSet;
}

void PmergeMe::insertPendingElements(std::deque<int> &mainSet, std::deque<int> &pendingSet)
{
    generateJacobstal(pendingSet.size());
    generateInsertionIndexWithJacobsthal(pendingSet.size());

    for (std::vector<int>::iterator it = _insertion.begin(); it != _insertion.end(); it++)
    {
        int value;
        std::deque<int>::iterator position;

        value = pendingSet[*it];
        position = std::upper_bound(mainSet.begin(), mainSet.end(), value);
        mainSet.insert(position, value);
    }
}
void PmergeMe::mergeInsertList(std::list<int> &array)
{
    std::list<int> mainSet, pendingSet;

    clock_t start = clock();
    pendingSet = createMainAndPendingSet(mainSet, array);

    insertPendingElements(mainSet, pendingSet);
    array = mainSet;
    clock_t end = clock();
    _elapsedList = double(end - start) / CLOCKS_PER_SEC;
    std::cout << YELLOW << "After:  ";
    for (std::list<int>::iterator it = array.begin(); it != array.end(); ++it)
    {
        printColor(*it, YELLOW);
    }
    std::cout << std::endl;
}

std::list<int> PmergeMe::createMainAndPendingSet(std::list<int> &mainSet, std::list<int> &array)
{
    size_t size = array.size();
    std::list<int> pendingSet;

    if (size <= 1)
        return pendingSet;

    std::list<int>::iterator it = array.begin();
    for (size_t i = 0; i < size; i += 2) 
    {
        std::list<int>::iterator next = it;
        ++next;
        if (next != array.end()) 
        {
            int maxVal = std::max(*it, *next);
            int minVal = std::min(*it, *next);

            std::list<int>::iterator mainPos = std::upper_bound(mainSet.begin(), mainSet.end(), maxVal);
            mainSet.insert(mainPos, maxVal);

            std::list<int>::iterator pendingPos = std::upper_bound(pendingSet.begin(), pendingSet.end(), minVal);
            pendingSet.insert(pendingPos, minVal);
            ++it;
        } 
        else 
        {
            std::list<int>::iterator mainPos = std::upper_bound(mainSet.begin(), mainSet.end(), *it);
            mainSet.insert(mainPos, *it);
        }
        ++it;
    }

    return pendingSet;
}

void PmergeMe::insertPendingElements(std::list<int> &mainSet, std::list<int> &pendingSet)
{
    std::vector<int>::iterator it;
    for (it = _insertion.begin(); it != _insertion.end(); ++it)
    {
        int value;
        std::list<int>::iterator position;

        if (static_cast<std::list<int>::size_type>(*it) < pendingSet.size()) {
            value = *advanceIterator(pendingSet.begin(), *it);
            position = std::upper_bound(mainSet.begin(), mainSet.end(), value);
            mainSet.insert(position, value);
        }
    }
}

std::list<int>::iterator PmergeMe::advanceIterator(std::list<int>::iterator it, size_t n)
{
    while (n-- > 0) {
        ++it;
    }
    return it;
}

bool PmergeMe::_validNumber(const std::string &expression)
{
    std::istringstream iss(expression);
    long long l;
    iss >> std::noskipws >> l;
    if (iss.eof() && !iss.fail())
    {
        return l > 0;
    }
    return false;
}

void PmergeMe::generateJacobstal(unsigned long n)
{
    _jacobsthalNumbers.clear();
    _jacobsthalNumbers.push_back(0);
    _jacobsthalNumbers.push_back(1);
    
    unsigned long nextNumber = *(_jacobsthalNumbers.rbegin() + 1) * 2 + _jacobsthalNumbers.back();

    while (nextNumber <= n)
    {
        _jacobsthalNumbers.push_back(nextNumber);
        nextNumber = *(_jacobsthalNumbers.rbegin() + 1) * 2 + _jacobsthalNumbers.back();
    }
    _jacobsthalNumbers.erase(_jacobsthalNumbers.begin() + 1);
}

void PmergeMe::generateInsertionIndexWithJacobsthal(unsigned long size)
{
    _insertion.push_back(_jacobsthalNumbers.front());

    while (_insertion.size() < size)
    {
        _jacobsthalNumbers.erase(_jacobsthalNumbers.begin());

        if (!_jacobsthalNumbers.empty())
        {
            int last = _insertion.back();
            int jacob = _jacobsthalNumbers.front();

            if (jacob > last && jacob < static_cast<int>(size))
            {
                _insertion.push_back(jacob--);

                while (jacob > last && _insertion.size() < size)
                {  
                    std::vector<int>::iterator it = _insertion.begin();
                    std::vector<int>::iterator ite = _insertion.end();

                    if (std::find(it, ite, jacob) == ite)
                        _insertion.push_back(jacob);

                    jacob--;
                }
            }
        }
        else
        {
            int missing = size - 1;
            while (_insertion.size() < size && missing > 0)
                _insertion.push_back(missing--);
        }
    }
}
