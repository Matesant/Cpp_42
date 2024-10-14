#include "./Whatever.hpp"

void	newLine(void);
void	thatIsAllFolks();
void	printHyphen(void);
void	pause(int milliseconds);
void	printTag(const std::string& str);

int	main(void)
{
	int	a;
	int	b;

	printHyphen();
	printTag("Values of a and b before swap");
	printHyphen();
	a = 2;
	b = 3;

	newLine();
	::printColor("a = " + toString(a), GREEN);
	::printColor("b = " + toString(b), GREEN);
	newLine();

	printHyphen();
	printTag("Values of a and b after swap");
	printHyphen();

	swap(a, b);

	newLine();
	::printColor("a = " + toString(a), GREEN);
	::printColor("b = " + toString(b), GREEN);
	newLine();

	printHyphen();
	printTag("Testing min and max functions");
	printHyphen();

	newLine();
	::printColor("min( a, b ) = " + toString(::min(a, b)), CYAN);
	::printColor("max( a, b ) = " + toString(::max(a, b)), CYAN);
	newLine();

	printHyphen();
	printTag("Testing with strings");
	printHyphen();

	newLine();
	std::string c = "Jorge";
	std::string d = "Carlos Eduardo de Aragão Jorge santos de oliveira";
	::swap(c, d);
	::printColor("c = " + c, GREEN);
	::printColor("d = " + d, GREEN);

	newLine();
	::printColor("min( c, d ) = " + ::min(c, d), CYAN);
	::printColor("max( c, d ) = " + ::max(c, d), CYAN);
	newLine();

	thatIsAllFolks();
	return (0);
}

void	newLine(void)
{
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

