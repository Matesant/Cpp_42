#include "MutantStack.hpp"

void        newLine(void);
void        thatIsAllFolks();
void        printTag(const std::string& str);

int main(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
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
