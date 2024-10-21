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

    std::cout << GREY << "After: ";
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it)
    {
        printColor(*it, GREY);
    }
    std::cout << std::endl;
}

void PmergeMe::mergeInsertDeque(std::deque<int> &array)
{
        std::deque<int> mainSet, pendingSet;
        pendingSet = createMainAndPendingSet(mainSet, array);

        std::sort(mainSet.begin(), mainSet.end());
        insertPendingElements(mainSet, pendingSet);
        array = mainSet;
}

std::deque<int> PmergeMe::createMainAndPendingSet(std::deque<int> &mainSet, std::deque<int> &array)
{
    size_t size = array.size();
    std::deque<int> pendingSet;

    if (size <= 1)
        return pendingSet;

    for (size_t i = 0; i < size; i += 2) 
    {
        if (i + 1 < size) {
            mainSet.push_back(std::max(array[i], array[i + 1]));
            pendingSet.push_back(std::min(array[i], array[i + 1]));
        } else {
            mainSet.push_back(array[i]);
        }
    }

    return pendingSet;
}

void PmergeMe::insertPendingElements(std::deque<int> &mainSet, std::deque<int> &pendingSet)
{
    generateJacobstal(pendingSet.size());
    generateInsertionIndexWithJacobsthal(pendingSet.size());

   
    for (std::vector<int>::iterator it = _insertion.begin(); it != _insertion.end(); ++it)
    {
        int value;
        std::deque<int>::iterator position;

        value = pendingSet[*it];
        position = std::upper_bound(mainSet.begin(), mainSet.end(), value);
        mainSet.insert(position, value);
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
    _insertion.clear();
    _insertion.push_back(_jacobsthalNumbers.front());

    while (_insertion.size() < size)
    {
        _jacobsthalNumbers.erase(_jacobsthalNumbers.begin());

        if (!_jacobsthalNumbers.empty())
        {
            int last = _insertion.back();
            int jacob = _jacobsthalNumbers.front();

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
        else
        {
            int missing = size - 1;
            while (_insertion.size() < size)
                _insertion.push_back(missing--);
        }
    }
    //print insertion green

    for (std::vector<int>::iterator it = _insertion.begin(); it != _insertion.end(); ++it)
    {
        printColor(*it, GREEN);
    }
    std::cout << std::endl;
}
