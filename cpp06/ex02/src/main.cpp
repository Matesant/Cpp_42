#include "./Base.hpp"

int	main(void)
{
	printColor("Generate random instance of A, B or C");
	newLine();
	Base *base = generate();
	newLine();

	printColor("Identify the instance type by pointer"); 
	newLine();
	identify(base);
	newLine();

	printColor("Identify the instance type by reference");
	newLine();
	identify(*base);
	newLine();

	delete base;
	return (0);
}
