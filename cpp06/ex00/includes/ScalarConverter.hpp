#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "Utils.hpp"

# define PSEUDO 6
# define CHAR 7
# define INT 8
# define FLOAT 9
# define DOUBLE 1

// Class declaration
class ScalarConverter
{
  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	~ScalarConverter();

	// methods
	static void convertChar(const std::string &str);
	static void convertInt(const std::string &str);
	static void convertFloat(const std::string &str);
	static void convertDouble(const std::string &str);
	static bool checkType(const std::string &str);
	static bool checkInt(const std::string &str);

	static const std::string _pseudoLiterals[6];
	static int _type;

  public:
	// methods
	static void convert(const std::string &str);
};

#endif // SCALARCONVERTER_HPP
