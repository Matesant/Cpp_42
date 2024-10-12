#include "./Whatever.hpp"

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
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	::printColor("c = " + c, GREEN);
	::printColor("d = " + d, GREEN);

	newLine();
	::printColor("min( c, d ) = " + ::min(c, d), CYAN);
	::printColor("max( c, d ) = " + ::max(c, d), CYAN);
	newLine();

	return (0);
}
