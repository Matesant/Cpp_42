#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "Utils.hpp"

// Class declaration
class ScalarConverter
{
  public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	~ScalarConverter();

	//methods
	static void convertToChar(std::string str);

  private:
};

#endif // SCALARCONVERTER_HPP
