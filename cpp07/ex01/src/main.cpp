#include "./Iter.hpp"

void	newLine(void)
{
	std::cout << std::endl;
}
inline double round(double x)
{
    return (x < 0.0) ? std::ceil(x - 0.5) : std::floor(x + 0.5);
}

void randonRound(const float& f)
{
	::printColor(round(f), MAGENTA);
}

void ifCharacterisOdd(const char& c)
{
	if (c % 2 == 0)
		::printColor("Even", CYAN);
	else
		::printColor("Odd", MAGENTA);
}

void ifNumberisPrime(const int& n)
{
	if (n < 2)
	{
		::printColor("Not Prime", RED);
		return;
	}
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			::printColor("Not Prime", RED);
			return;
		}
	}
	::printColor("Prime", GREEN);
}

#include <iostream>
#include <unistd.h> // Para usleep

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
    int extraHyphen = (totalWidth - strLength) % 2; // Para lidar com strings de comprimento ímpar

    std::string hyphens(hyphensEachSide, '-');
    std::cout << YELLOW << INVERSE << hyphens << str << hyphens << std::string(extraHyphen, '-') << RESET << std::endl;
}

void	printHyphen(void)
{
	std::cout << YELLOW << INVERSE << "------------------------------------------------------------" << RESET << std::endl;
}

int	main(void)
{
	char cArray[] = {'a', 'b', 'c', 'd'};
	int iArray[] = {1, 2, 3, 4, 5};
	float fArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

	printHyphen();
	printTag("Int Array");
	printHyphen();

	newLine();
	::Iter(iArray, 5, ::printColorOrange);
	newLine();

	printHyphen();
	printTag("Testing ifNumberisPrime with Iterator");
	printHyphen();

	newLine();
	::Iter(cArray, 5, ::ifCharacterisOdd);
	newLine();

	printHyphen();
	printTag("Testing randonRound with Iterator");
	printHyphen();

	newLine();
	::Iter(fArray, 5, ::randonRound);
	newLine();

	printHyphen();
	thatIsAllFolks();

	return (0);
}
