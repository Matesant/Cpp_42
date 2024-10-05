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
