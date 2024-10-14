#include "easyfind.hpp"

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
	int array[] = {1, 2, 4, 5};
	std::vector<int> vector(array, array + 5);

	printHyphen();
	printTag("Testing easyfind");
	printHyphen();

	try {
		printColor(*easyfind(vector, 3), GREEN);
	} catch (std::exception& e) {
		printColor(e.what(), RED);
	}
	newLine();
	thatIsAllFolks();
	return (0);
}
