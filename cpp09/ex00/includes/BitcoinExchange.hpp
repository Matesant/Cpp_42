#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define ORANGE "\033[38;5;208m"
# define PINK "\033[38;5;213m"
# define PURPLE "\033[38;5;135m"
# define GREY "\033[38;5;246m"
# define BROWN "\033[38;5;130m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;95m"
# define BLUE "\033[1;34m"
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define INVERSE "\033[7m"

# include <algorithm>
# include <cmath>
# include <cstdio>
# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <stdexcept>
# include <string>

template <typename T> std::string toString(const T &value);

template <typename T> void printColor(const T &value, const std::string &color);

class BitcoinExchange
{
  private:
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	std::map<std::string, double> _database;

	// database csv methods
	void _saveDatabase(void);
	bool _validateLineData(const std::string &line);
	bool _validValue(const std::string &value, std::string &error);

	bool _isValidHeader(const std::string &header);
	void _validateFile(std::ifstream &file);
	
	// input validation methods
	bool _validateLine(const std::string &line);
	bool _validateDataInput(const std::string &date, std::string &error);
	bool _validValueInput(const std::string &value, std::string &error);
	bool _DateLengthAndHyphensAreValid(const std::string &date,
		std::string &error);
	bool _isValidDate(int day, int month, int year, std::string &error);
	
	// exchange rate methods
	void _writeExchangeInTerminal(const std::string &date, double value);
	double _getClosestExchangeRate(const std::string &date);

  public:
	BitcoinExchange(void);
	~BitcoinExchange(void);

	void _processFile(const std::string &filename);

	class InvalidFile : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Invalid file");
		}
	};
};

template <typename T> std::string toString(const T &value)
{
	std::stringstream ss;
	ss << value;
	return (ss.str());
}

template <typename T> void printColor(const T &value, const std::string &color)
{
	std::cout << color << toString(value) << RESET << std::endl;
}

#endif