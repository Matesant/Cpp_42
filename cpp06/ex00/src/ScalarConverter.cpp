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
		case CHAR:
			convertChar(str);
			break;
	}
}

bool ScalarConverter::checkType(const std::string &str)
{
	_str = str;
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
			if (dot > 1 || ((!isdigit(str[i]) && str[i] != '.') && ((i != (int)str.length() -1) && (str[i] != 'f'))))
			{
				std::cout << "Error: invalid input" << std::endl;
				return true;
			}
		}
		if (isdigit(str[i]))
			i++;
	}
	if (dot == 0 && str[str.length() - 1] == 'f')
	{
		std::cout << "Error: invalid input" << std::endl;
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

int ScalarConverter::_type = PSEUDO;
std::string ScalarConverter::_str = "";

void ScalarConverter::printChar(char c)
{
	if (atol(_str.c_str()) < -128 || atol(_str.c_str()) > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	std::cout << "char: ";
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i)
{
	std::cout << "int: ";
	if (i >= INT_MIN && i <= INT_MAX)
		std::cout << i << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	std::cout << "float: ";
	if (f >= FLT_MIN && f <= FLT_MAX)
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	std::cout << "double: ";
	if (d >= DBL_MIN && d <= DBL_MAX)
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	else
		std::cout << "impossible" << std::endl;
}