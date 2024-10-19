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
void BitcoinExchange::_writeExchangeInTerminal(const std::string &date, double value)
{
	double exchangeRate = _getClosestExchangeRate(date);
	double result = value * exchangeRate;
	std::cout << YELLOW << date 
	<< GREY << " | " << PINK << value 
	<< GREY << " * " << BLUE << exchangeRate 
	<< GREY << " = " << ORANGE << result << std::endl;
}

double BitcoinExchange::_getClosestExchangeRate(const std::string &date)
{
    std::map<std::string, double>::iterator it = _database.find(date);
    if (it != _database.end())
    {
        return it->second;
    }

    std::map<std::string, double>::iterator lower = _database.lower_bound(date);
    if (lower == _database.begin())
    {
        return lower->second;
    }
    if (lower == _database.end())
    {
        return (--lower)->second;
    }

    std::map<std::string, double>::iterator prev = lower;
    --prev;
    if (std::abs(std::atoi(date.c_str()) - std::atoi(prev->first.c_str())) <= std::abs(std::atoi(lower->first.c_str()) - std::atoi(date.c_str())))
    {
        return prev->second;
    }
    else
    {
        return lower->second;
    }
}

void BitcoinExchange::_saveDatabase(void)
{
	std::ifstream *file = _validateFile("data.csv");

	if (file->is_open())
	{
		std::string line;
		std::getline(*file, line);
		_isValidHeader(line);
		while (std::getline(*file, line))
		{
			std::string date;
			std::string value;
			std::string::size_type pos = line.find(',');
			if (pos != std::string::npos)
			{
				if (pos + 1 < line.size())
				{
					if (!_validateLineData(line))
						continue;
					date = line.substr(0, pos);
					value = line.substr(pos + 1);
					_database[date] = std::atof(value.c_str());
				}
			}
		}
		delete file;
	}
	else
	{
		printColor("Invalid file", RED);
		return ;
	}
}

void BitcoinExchange::_processFile(const std::string &filename)
{
	std::ifstream *file = _validateFile(filename);

	if (file->is_open())
	{
		std::string line;
		std::getline(*file, line);
		_isValidHeader(line);
		std::cout << YELLOW << "date" << GREY << " | " << PINK << "value" << RESET << std::endl;
		while (std::getline(*file, line))
		{
			std::string date;
			std::string value;
			std::string::size_type pos = line.find('|');
			if (pos != std::string::npos)
			{
				if (pos + 1 < line.size())
				{
					if (!_validateLine(line))
						continue;
					date = line.substr(0, pos - 1);
					value = line.substr(pos + 2);
					_writeExchangeInTerminal(date, std::atof(value.c_str()));
				}
			}	
		}
		delete file;
	}
	else
	{
		printColor("Invalid file", RED);
		return ;
	}
}

bool BitcoinExchange::_validateLine(const std::string &line)
{
	std::string::size_type pos = line.find('|');
	if (pos == std::string::npos)
	{
		throw InvalidFile();
	}
	std::string date = line.substr(0, pos - 1);
	std::string value = line.substr(pos + 2);
	std::string error;
	if (!_validateDataInput(date, error) || !_validValueInput(value, error))
	{
		printColor(error, RED);
		return false;
	}
	return true;
}

std::ifstream* BitcoinExchange::_validateFile(const std::string &filename)
{
	std::ifstream *file = new std::ifstream (filename.c_str());
	if (file->is_open())
	{
		return (file);
	}
	else
	{
		throw InvalidFile();
	}
}

bool BitcoinExchange::_validateLineData(const std::string &line)
{
	std::string error;

	std::string::size_type pos = line.find(',');
	if (pos == std::string::npos)
	{
		throw InvalidFile();
	}
	std::string date = line.substr(0, pos);
	std::string value = line.substr(pos + 1);
	if (!_validateDataInput(date, error) || !_validValue(value, error))
	{
		printColor(error, RED);
		return false;	
	}
	return true;
}
bool BitcoinExchange::_validateDataInput(const std::string &date, std::string &error)
{
	int day, month, year;

	if (!_DateLengthAndHyphensAreValid(date, error))
		return false;
	if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3) {
		error = "Invalid date format: unable to parse year, month, and day";
		return false;
	}
	if (!_isValidDate(day, month, year, error))
		return false;
	return true;
}

bool BitcoinExchange::_DateLengthAndHyphensAreValid(const std::string &date, std::string &error)
{
	if (date.size() != 10) {
		error = "Invalid date format: incorrect length";
		return false;
	}
	if (date[4] != '-' || date[7] != '-') {
		error = "Invalid date format: expected '-' at positions 5 and 8";
		return false;
	}
	for (size_t i = 0; i < date.size(); ++i) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i])) {
			error = "Invalid date format: non-digit characters found";
			return false;
		}
	}
	return true;
}

bool BitcoinExchange::_isValidDate(int day, int month, int year, std::string &error)
{
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
		error = "Invalid date: out of range values for year, month, or day";
		return false;
	}
	if (month == 2) {
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
			if (day > 29) {
				error = "Invalid date: February in a leap year cannot have more than 29 days";
				return false;
			}
		} else if (day > 28) {
			error = "Invalid date: February cannot have more than 28 days";
			return false;
		}
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) {
			error = "Invalid date: the month cannot have more than 30 days";
			return false;
		}
	}
	return true;
}

bool BitcoinExchange::_validValue(const std::string &value, std::string &error)
{
	std::istringstream iss(value);
	float f;
	iss >> std::noskipws >> f;
	if (iss.eof() && !iss.fail()) {
		return true;
	} else {
		error = "Invalid value format: unable to parse value";
		return false;
	}
}

bool BitcoinExchange::_validValueInput(const std::string &value, std::string &error)
{
	char* end;
	double f = std::strtod(value.c_str(), &end);
	if (*end != '\0') {
		error = "Invalid value format: unable to parse value";
		return false;
	}
	if (f < 0 || f > 1000) {
		error = "Invalid value: out of range (0-1000)";
		return false;
	}
	return true;
}

bool BitcoinExchange::_isValidHeader(const std::string &header)
{
	if (header != "date,exchange_rate" && header != "date | value")
	{
		throw InvalidFile();
	}
	return true;
}