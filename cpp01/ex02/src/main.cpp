#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of str: " << &str << std::endl;
	std::cout << "Address of ptr: " << stringPTR << std::endl;
	std::cout << "Address of ref: " << &stringREF << std::endl;

	std::cout << "Value of String: " << str << std::endl;
	std::cout << "Value pointed by Pointer: " << *stringPTR << std::endl;
	std::cout << "Value pointed by Reference: " << stringREF << std::endl;
	return (0);
}