# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	_saveDatabase();
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

void BitcoinExchange::_saveDatabase(void)
{
	std::ifstream file("data.csv");

	if (file.is_open())
	{
		std::string line;
		std::getline(file, line);
		while (std::getline(file, line))
		{
			std::string date;
			std::string value;
			std::string::size_type pos = line.find(',');
			if (pos != std::string::npos)
			{
				if (pos + 1 < line.size())
				{
					date = line.substr(0, pos);
					value = line.substr(pos + 1);
					_validateLineData(line);
					_database[date] = std::atof(value.c_str());
				}
			}
		}
		file.close();
	}
	else
	{
		printColor("Invalid file", RED);
		return ;
	}
}

void BitcoinExchange::_processFile(const std::string &filename)
{
	std::ifstream file(filename.c_str());

	if (file.is_open())
	{
		std::string line;
		std::getline(file, line);
		_validateLine(line);
		while (std::getline(file, line))
		{
			std::string date;
			std::string value;
			std::string::size_type pos = line.find('|');
			if (pos != std::string::npos)
			{
				if (pos + 1 < line.size())
				{
					_validateLine(line);
					date = line.substr(0, pos);
					value = line.substr(pos + 1);
					_writeLine(date, std::atof(value.c_str()));
				}
			}	
		}
		file.close();
	}
	else
	{
		printColor("Invalid file", RED);
		return ;
	}
}

void BitcoinExchange::_writeLine(const std::string &date, double value)
{
	std::ofstream file("data.csv", std::ios::app);

	if (file.is_open())
	{
		file << date << "," << value << std::endl;
		file.close();
	}
	else
	{
		throw InvalidFile();
	}
}

void BitcoinExchange::_validateLine(const std::string &line)
{
	std::string::size_type pos = line.find('|');
	if (pos == std::string::npos)
	{
		throw InvalidFile();
	}
	std::string date = line.substr(0, pos);
	std::string value = line.substr(pos + 1);
	if (date.find("date") != std::string::npos || value.find("value") != std::string::npos)
		return;
	if (date.size() != 10)
	{
		throw InvalidFile();
	}
	if (value.size() == 0)
	{
		throw InvalidFile();
	}
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
			{
				printColor("jorge", RED);
			}
		}
		else
		{
			if (!std::isdigit(date[i]))
			{
				printColor("tobias", RED);
			}
		}
	}
	for (size_t i = 0; i < value.size(); i++)
	{
		if (!std::isdigit(value[i]) && value[i] != '.')
		{
			printColor("sabrina", YELLOW);
		}
	}
}

void BitcoinExchange::_validateLineData(const std::string &line)
{
	std::string::size_type pos = line.find(',');
	if (pos == std::string::npos)
	{
		throw InvalidFile();
	}
	std::string date = line.substr(0, pos);
	std::string value = line.substr(pos + 1);
	if (date.size() != 10)
	{
		throw InvalidFile();
	}
	if (value.size() == 0)
	{
		throw InvalidFile();
	}
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
			{
				throw InvalidFile();
			}
		}
		else
		{
			if (!std::isdigit(date[i]))
			{
				throw InvalidFile();
			}
		}
	}
	for (size_t i = 0; i < value.size(); i++)
	{
		if (!std::isdigit(value[i]) && value[i] != '.')
		{
			throw InvalidFile();
		}
	}
}

