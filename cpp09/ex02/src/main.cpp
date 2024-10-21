#include "PmergeMe.hpp"


void    newLine(void);
void    thatIsAllFolks();
void    pause(int milliseconds);

int	main(int argc, char **argv)
{  
    PmergeMe Fjhonson;

	if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " [number1] [number2] ... [numberN]" << std::endl;
        return 1;
    }

	Fjhonson.parseGood(argc, argv);
	
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
