#include "ScalarConverter.hpp"

const std::string ScalarConverter::_pseudoLiterals[6] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &str)
{
	if (checkType(str))
		return;
	switch (_type)
	{
		case PSEUDO:
			printPseudo();
			break;
		case CHAR:
			convertChar(str);
			break;
		case INT:
			convertInt(str);
			break;
		case FLOAT:
			convertFloat(str);
			break;
		case DOUBLE:
			convertDouble(str);
			break;
	}
}

bool ScalarConverter::checkType(const std::string &str)
{
	_str = str;
	int i = 0;

	while (i < 6)
	{
		if (str == _pseudoLiterals[i])
		{
			_type = PSEUDO;
			return false;
		}
		i++;
	}
	if (str.length() == 1 && !isdigit(str[0]))
	{
		_type = CHAR;
		return false;
	}
	if (checkInt(str))
		return true;
	return false;
}

bool ScalarConverter::checkInt(const std::string &str)
{
	int i = 0;
	int dot = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (i < (int)str.length())
	{
		if (str[i] == '.')
        {
            dot++;
            if (dot > 1)
            {
                std::cout << RED << "Error: invalid input" << RESET << std::endl;
                return true;
            }
        }
        else if (!isdigit(str[i]) && !(str[i] == 'f' && i == (int)str.length() - 1))
        {
            std::cout << RED << "Error: invalid input" << RESET << std::endl;
            return true;
        }
			i++;
	}
	if (dot == 0 && str[str.length() - 1] == 'f')
	{
		std::cout << RED << "Error: invalid input" << RESET << std::endl;
		return true;
	}	
	else if (dot == 1)
		_type = (str[str.length() - 1] == 'f') ? FLOAT : DOUBLE;
	else
		_type = INT;
	return false;
}

void ScalarConverter::convertChar(const std::string &str)
{
	char c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	
	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}


void ScalarConverter::convertInt(const std::string &str)
{
	int i = atoi(str.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::convertFloat(const std::string &str)
{
	float f = atof(str.c_str());
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::convertDouble(const std::string &str)
{
	double d = atof(str.c_str());
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::printPseudo()
{
	std::cout << RED << "char: impossible" << RESET << std::endl;
	std::cout << RED << "int: impossible" << RESET << std::endl;
	if (_str == "nan" || _str == "nanf")
		{
			std::cout << BLUE << "float: nanf" << RESET << std::endl;
			std::cout << MAGENTA << "double: nan" << RESET << std::endl;
		}
	else if (_str == "+inf" || _str == "+inff")
		{
			std::cout << BLUE << "float: inff" << RESET << std::endl;
			std::cout << MAGENTA << "double: inf" << RESET << std::endl;
		}
	else if (_str == "-inf" || _str == "-inff")
		{
			std::cout << BLUE << "float: -inff" <<RESET <<  std::endl;
			std::cout << MAGENTA << "double: -inf" <<RESET <<  std::endl;
		}
}

void ScalarConverter::printChar(char c)
{
	if (atol(_str.c_str()) < -128 || atol(_str.c_str()) > 127)
	{
		std::cout << RED << "char: impossible" << RESET << std::endl;
		return;
	}
	if (isprint(c))
		std::cout << GREEN << "char: '" << c << "'" << RESET << std::endl;
	else
		std::cout << RED << "char: Non displayable" << RESET << std::endl;
}

void ScalarConverter::printInt(int i)
{
	if (i < INT_MIN || i > INT_MAX)
	{
		std::cout << RED << "int: impossible" << RESET << std::endl;
		return;
	}
	std::cout << YELLOW << "int: " << i << RESET << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	if (f >= FLT_MIN && f <= FLT_MAX)
		std::cout << BLUE << "float: " << std::fixed << std::setprecision(1) << f << "f" << RESET << std::endl;
	else
		std::cout << RED << "float: impossible" << RESET << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	if (d >= DBL_MIN && d <= DBL_MAX)
		std::cout << MAGENTA << "double: " << std::fixed << std::setprecision(1) << d << RESET << std::endl;
	else
		std::cout << RED << "double: impossible" << RESET << std::endl;
}
int ScalarConverter::_type = PSEUDO;
std::string ScalarConverter::_str = "";
