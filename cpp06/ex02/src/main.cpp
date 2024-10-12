#include "./Base.hpp"

int	main(void)
{
	printHyphen();
	printColor("Generate random instance of A, B or C");
	printHyphen();

	newLine();
	Base *base = generate();
	newLine();

	printHyphen();
	printColor("Identify the instance type by pointer"); 
	printHyphen();

	newLine();
	identify(base);
	newLine();

	printHyphen();
	printColor("Identify the instance type by reference");
	printHyphen();

	newLine();
	identify(*base);
	newLine();

	delete base;
	return (0);
}
