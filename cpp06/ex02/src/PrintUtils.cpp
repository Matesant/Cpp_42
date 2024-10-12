#include "Utils.hpp"

void newLine(void)
{
	std::cout << std::endl;
}

void printColor(const std::string& str) 
{
    const int totalWidth = 60;
    int strLength = str.length();
    if (strLength >= totalWidth) {
        std::cout << str << std::endl;
        return;
    }

    int hyphensEachSide = (totalWidth - strLength) / 2;
    int extraHyphen = (totalWidth - strLength) % 2; // Para lidar com strings de comprimento ímpar

    std::string hyphens(hyphensEachSide, '-');
    std::cout << YELLOW << INVERSE << hyphens << str << hyphens << std::string(extraHyphen, '-') << RESET << std::endl;
}

void printHyphen(void)
{
	std::cout << YELLOW << INVERSE << "------------------------------------------------------------" << RESET << std::endl;
}