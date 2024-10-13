#include "./Array.hpp"

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

    int hyphensEachSide = (totalWidth - strLength) / 2;
    int extraHyphen = (totalWidth - strLength) % 2;

    std::string hyphens(hyphensEachSide, '-');
    std::cout << YELLOW << INVERSE << hyphens << str << hyphens << std::string(extraHyphen, '-') << RESET << std::endl;
}

void	printHyphen(void)
{
	std::cout << YELLOW << INVERSE << "------------------------------------------------------------" << RESET << std::endl;
}

int	main(void)
{
	::Array<int> array3(5);

	::printHyphen();
	::printTag("Printing array3");
	::printHyphen();
	newLine();

	for (unsigned int i = 0; i < array3.size(); i++)
	{
		array3[i] = i;
		::printColor("array3[" + ::toString(i) + "] = " + ::toString(array3[i]), CYAN);
	}
	newLine();

	::printHyphen();
	::printTag("Printing array size");
	::printHyphen();

	newLine();
	::printColor("array3.size() = " + ::toString(array3.size()), CYAN);
	newLine();

	::printHyphen();
	::printTag("Testing assignation operator, array3 numbers + 10");
	::printHyphen();

	::Array<int> array2(5);

	newLine();
	for (unsigned int i = 0; i < array2.size(); i++)
	{
		array2[i] = i + 10;
		::printColor("array2[" + ::toString(i) + "] = " + ::toString(array2[i]), CYAN);
	}
	newLine();

	::printHyphen();
	::printTag("Testing copy constructor");
	::printHyphen();

	::Array<int> array4(array3);

	newLine();
	for (unsigned int i = 0; i < array4.size(); i++)
	{
		::printColor("array4[" + ::toString(i) + "] = " + ::toString(array4[i]), CYAN);
	}
	newLine();

	::printHyphen();
	::printTag("Try to access an element out of limits");
	::printHyphen();

	newLine();
	try
	{
		::printColor("array4[5] = " + ::toString(array4[5]), CYAN);
	}
	catch (std::exception& e)
	{
		::printColor(e.what(), RED);
	}
	newLine();

	::printHyphen();
	::printTag("Try to access an element a const out of limits");
	::printHyphen();

	newLine();
	const ::Array<int> array5(array4);
	try
	{
		::printColor("array5[5] = " + ::toString(array5[5]), CYAN);
	}
	catch (std::exception& e)
	{
		::printColor(e.what(), RED);
	}
	newLine();
	::printHyphen();

	newLine();
	thatIsAllFolks();
	return (0);
}
