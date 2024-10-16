#include "BitcoinExchange.hpp"


void    newLine(void);
void    thatIsAllFolks();
void    pause(int milliseconds);
void    printTag(const std::string& str);


int	main(int argc, char **argv)
{  
    if (argc != 2)
    {
        std::cerr << "Usage: ./bitcoinExchange <filename>" << std::endl;
        return 1;
    }
    else
    {
        printTag("Bitcoin Exchange");
        BitcoinExchange exchange(argv[1]);
        exchange.run();
    }
	
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


