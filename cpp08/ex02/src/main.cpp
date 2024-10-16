#include "MutantStack.hpp"
#include <list>

void        newLine(void);
void        thatIsAllFolks();
void        printTag(const std::string& str);

int main(void)
{
    printTag("Subject test");
    newLine();

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    newLine();

    printTag("testing with container list");
    newLine();

    MutantStack<std::list<int> > mstack2;
    mstack2.push(std::list<int>(5, 42));
    mstack2.push(std::list<int>(3, 21));
    mstack2.push(std::list<int>(2, 11));
    mstack2.push(std::list<int>(1, 1));
    
    MutantStack<std::list<int> >::iterator it2 = mstack2.begin();
    MutantStack<std::list<int> >::iterator ite2 = mstack2.end();

    while (it2 != ite2)
    {
        std::list<int>::iterator it3 = it2->begin();
        std::list<int>::iterator ite3 = it2->end();
        while (it3 != ite3)
        {
            printColorNoNewLine(*it3, GREEN);
            ++it3;
        }
        std::cout << std::endl;
        ++it2;
    }

    printTag("Testing with container vector");
    newLine();

    MutantStack<std::vector<int> > mstack3;
    mstack3.push(std::vector<int>(5, 42));
    mstack3.push(std::vector<int>(3, 21));
    mstack3.push(std::vector<int>(2, 11));
    mstack3.push(std::vector<int>(1, 1));

    MutantStack<std::vector<int> >::iterator it4 = mstack3.begin();
    MutantStack<std::vector<int> >::iterator ite4 = mstack3.end();

    while (it4 != ite4)
    {
        std::vector<int>::iterator it5 = it4->begin();
        std::vector<int>::iterator ite5 = it4->end();
        while (it5 != ite5)
        {
            printColorNoNewLine(*it5, GREEN);
            ++it5;
        }
        std::cout << std::endl;
        ++it4;
    }
    
    newLine();
    thatIsAllFolks();
    return 0;
}

void	newLine(void)
{
	std::cout << std::endl;
}

void thatIsAllFolks()
{
    const char* message = "That's all folks!";
    const int delay = 100000;
    const char* colors[] = {YELLOW, GREEN, CYAN, MAGENTA, BLUE, RED};
    const int numColors = sizeof(colors) / sizeof(colors[0]);
    for (int i = 0; message[i] != '\0'; ++i)
    {
        std::cout << colors[i % numColors] << message[i] << RESET;
        std::cout.flush();
        usleep(delay);
    }
    std::cout << std::endl;
}

void printTag(const std::string& str) 
{
    const int totalWidth = 60;
    int strLength = str.length();
    if (strLength >= totalWidth) {
        std::cout << str << std::endl;
        return;
    }

	std::cout << YELLOW << INVERSE << "------------------------------------------------------------" << RESET << std::endl;
    int hyphensEachSide = (totalWidth - strLength) / 2;
    int extraHyphen = (totalWidth - strLength) % 2;

    std::string hyphens(hyphensEachSide, '-');
    std::cout << YELLOW << INVERSE << hyphens << str << hyphens << std::string(extraHyphen, '-') << RESET << std::endl;
	std::cout << YELLOW << INVERSE << "------------------------------------------------------------" << RESET << std::endl;
}
