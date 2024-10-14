#include "Utils.hpp"

void newLine(void)
{
	std::cout << std::endl;
}

void printColor(const std::string& str) 
{
    std::cout << YELLOW << INVERSE << "------------------------------------------------------------" << RESET << std::endl;
    const int totalWidth = 60;
    int strLength = str.length();
    if (strLength >= totalWidth) {
        std::cout << str << std::endl;
        return;
    }

    int hyphensEachSide = (totalWidth - strLength) / 2;
    int extraHyphen = (totalWidth - strLength) % 2;

    std::string hyphens(hyphensEachSide, '-');
    std::cout << YELLOW << INVERSE << hyphens << str << hyphens << std::string(extraHyphen, '-') << RESET << std::endl;
    std::cout << YELLOW << INVERSE << "------------------------------------------------------------" << RESET << std::endl;
}
