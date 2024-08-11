#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
		for (int i = 1; i < argc; i++)
		{
			std::string argv_type_str = argv[i];
			for (size_t character = 0; character < argv_type_str.length(); character++)
			{
				std::cout << (char)std::toupper(argv_type_str[character]);
			}
			std::cout << ' ';
		}
	std::cout << std::endl;
	return (0);
}