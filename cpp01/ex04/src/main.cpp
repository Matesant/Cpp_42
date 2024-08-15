/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:51:20 by matesant          #+#    #+#             */
/*   Updated: 2024/08/15 19:33:26 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Replace.hpp"

bool checkArgc(int argc)
{
	if (argc != 4)
	{
		std::cout << BOLD << BRIGHT_RED << "The program needs 3 parameters." << RESET << std::endl;
		return (false);
	}
	return (true);
}

bool mySed(std::ifstream &file, std::string needle, std::string haystack, Replace newSed)
{
	std::ofstream output;
	output.open((newSed.getFilename() + ".replace").c_str());
	if (!output.is_open())
	{
		std::cout << BOLD << BRIGHT_RED << "Error: " << RESET << "Could not open output file." << std::endl;
		return (1);
	}	
	for (std::string line; std::getline(file, line);)
	{
		size_t pos = 0;
		while ((pos = line.find(haystack, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + needle + line.substr(pos + haystack.length());
			pos += needle.length();
		}
		output << line << std::endl;
	}
	output.close();
	return (0);
}


int	main(int argc, char **argv)
{
	if (!checkArgc(argc))
		return (1);
	
	Replace newSed = Replace(argv[1], argv[2], argv[3]);	
	newSed.formatExtension();
	std::cout << BOLD << BRIGHT_GREEN << "File: " << RESET << newSed.getFilename() << std::endl;
	std::cout << BOLD << BRIGHT_GREEN << "Replacing " << newSed.getNeedle() << " with " << newSed.getHaystack() << " in " << newSed.getFilename() << std::endl;
	std::ifstream file(newSed.getFilename().c_str());
	if (!file.is_open())
	{
		std::cout << BOLD << BRIGHT_RED << "Error: " << RESET << "Could not open file." << std::endl;
		return (1);
	}
	if (mySed(file, newSed.getNeedle(), newSed.getHaystack(), newSed))
		return (1);
	file.close();
	return (0);
}
