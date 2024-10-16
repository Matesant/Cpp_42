# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	std::ifstream file = validadeFile(filename);
	readFile(filename);
}

std::ifstream BitcoinExchange::validadeFile(const std::string &filename)
{
	std::ifstream file(filename);

	if (!file.is_open())
		throw InvalidFile();
	return (file);
}

void BitcoinExchange::validateLine(const std::string &line)
{
}

void BitcoinExchange::validateValue(const std::string &line)
{
}

void BitcoinExchange::validateDate(const std::string &line)
{
}
