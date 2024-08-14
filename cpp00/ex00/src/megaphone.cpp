#include <iostream>
#include <string>

bool checkArgc(int argc)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (false);
	}
	return (true);
}

int main(int argc, char **argv)
{
	if (checkArgc(argc))
		for (int i = 1; i < argc; i++)
		{
			std::string argvTypeStr = argv[i];
			for (size_t character = 0; character < argvTypeStr.length(); character++)
				std::cout << (char)std::toupper(argvTypeStr[character]);
			std::cout << ' ';
		}
	std::cout << std::endl;
	return (0);
}