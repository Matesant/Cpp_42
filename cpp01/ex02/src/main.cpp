#include <string>
#include <iostream>

const std::string CYAN = "\033[36m";
const std::string BOLD = "\033[1m";
const std::string INVERSE = "\033[7m";
const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << BOLD << INVERSE << CYAN <<  "Addresses :" << RESET << std::endl;
	std::cout << BOLD << GREEN << "Address of str: " << RED << &str << std::endl;
	std::cout << BOLD << GREEN << "Address of ptr: " << RED << stringPTR << std::endl;
	std::cout << BOLD << GREEN << "Address of ref: " << RED << &stringREF << RESET << std::endl;

	std::cout << BOLD << INVERSE << CYAN << "Values :" << RESET << std::endl;
	std::cout << BOLD << GREEN << "Value of String: " << RED << str << std::endl;
	std::cout << BOLD << GREEN << "Value pointed by Pointer: " << RED << *stringPTR << std::endl;
	std::cout << BOLD << GREEN << "Value pointed by Reference: " << RED << stringREF << std::endl;
	return (0);
}