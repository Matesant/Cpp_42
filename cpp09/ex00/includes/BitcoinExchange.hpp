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

	void _saveDatabase(void);
	void _validateLineData(const std::string &line);
	void _validateLine(const std::string &line);
	void _writeLine(const std::string &date, double value);
	// void			validateValue(const std::string &line);
	// void			validateDate(const std::string &line);

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