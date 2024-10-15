#include "easyfind.hpp"


void    newLine(void);
void    thatIsAllFolks();
void    pause(int milliseconds);
void    printTag(const std::string& str);


int	main(void)
{
	int array[] = {1, 2, 3, 4, 5, 10, 60, 300, 44, 63};
    std::vector<int> vector(array, array + 10);

    newLine();
    printTag("Finding numbers in vector");
    newLine();

    try {
        printColor(*easyfind(vector, 3), GREEN);
        printColor(*easyfind(vector, 5), GREEN);
        printColor(*easyfind(vector, 10), GREEN);
        printColor(*easyfind(vector, 60), GREEN);
        printColor(*easyfind(vector, 300), GREEN);
    } catch (std::exception& e) {
        printColor(e.what(), RED);
    }
    newLine();

    // Teste com std::list
    std::list<int> lst(array, array + 10);
    printTag("Finding numbers in list");
    newLine();

    try {
        printColor(*easyfind(lst, 3), GREEN);
        printColor(*easyfind(lst, 5), GREEN);
        printColor(*easyfind(lst, 10), GREEN);
        printColor(*easyfind(lst, 60), GREEN);
        printColor(*easyfind(lst, 300), GREEN);
    } catch (std::exception& e) {
        printColor(e.what(), RED);
    }
    newLine();

    // Teste com std::deque
    std::deque<int> deq(array, array + 10);
    printTag("Finding numbers in deque");
    newLine();

    try {
        printColor(*easyfind(deq, 3), GREEN);
        printColor(*easyfind(deq, 5), GREEN);
        printColor(*easyfind(deq, 10), GREEN);
        printColor(*easyfind(deq, 60), GREEN);
        printColor(*easyfind(deq, 300), GREEN);
    } catch (std::exception& e) {
        printColor(e.what(), RED);
    }
    newLine();

    // Teste com contêiner vazio
    std::vector<int> emptyVector;
    printTag("Finding number in empty vector");
    newLine();

    try {
        printColor(*easyfind(emptyVector, 1), GREEN);
    } catch (std::exception& e) {
        printColor(e.what(), RED);
    }
    newLine();

    // Teste com valores duplicados
    int duplicateArray[] = {1, 2, 3, 3, 4, 5};
    std::vector<int> duplicateVector(duplicateArray, duplicateArray + 6);
    printTag("Finding number in vector with duplicates");
    newLine();

    try {
        printColor(*easyfind(duplicateVector, 3), GREEN);
    } catch (std::exception& e) {
        printColor(e.what(), RED);
    }
    newLine();

    // Teste com um único elemento
    int singleElementArray[] = {42};
    std::vector<int> singleElementVector(singleElementArray, singleElementArray + 1);
    printTag("Finding number in single element vector");
    newLine();

    try {
        printColor(*easyfind(singleElementVector, 42), GREEN);
    } catch (std::exception& e) {
        printColor(e.what(), RED);
    }
    newLine();

    thatIsAllFolks();
    return 0;
}

void	newLine(void)
{
	std::cout << std::endl;
}

void pause(int milliseconds)
{
    clock_t end_time = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
    while (clock() < end_time);
}

void thatIsAllFolks()
{
    const char* message = "That's all folks!";
    const int delay = 100;
    const char* colors[] = {YELLOW, GREEN, CYAN, MAGENTA, BLUE, RED};
    const int numColors = sizeof(colors) / sizeof(colors[0]);
    for (int i = 0; message[i] != '\0'; ++i)
    {
        std::cout << colors[i % numColors] << message[i] << RESET;
        std::cout.flush();
        pause(delay);
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


