# include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::~RPN(void)
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

void RPN::calculate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;
	std::stack<double> stack;

	if (!_validExpression(expression))
	{
		printColor("Invalid expression", RED);
		return ;
	}
	while (iss >> token)
	{
		if (_isOperator(token))
		{
			if (stack.size() < 2)
			{
				printColor("Invalid expression", RED);
				return ;
			}
			double operand2 = stack.top();
			stack.pop();
			double operand1 = stack.top();
			stack.pop();
			double result = _applyTheMathematics(operand1, operand2, token);
			stack.push(result);
		}
		else
			stack.push(std::atof(token.c_str()));
	}
	printColor(stack.top(), GREEN);
}

bool RPN::_validExpression(const std::string &expression)
{
	if (expression.empty())
		return false;
	for (size_t i = 0; i < expression.size(); i++)
	{
		if (!std::isdigit(expression[i]) && !std::isspace(expression[i]) && expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/')
			return false;
	}
	return true;
}

bool RPN::_isOperator(const std::string &token)
{
	if (token.size() != 1)
		return false;
	if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
		return true;
	return false;
}

double RPN::_applyTheMathematics(double operand1, double operand2, const std::string &token)
{
	if (token[0] == '+')
		return operand1 + operand2;
	if (token[0] == '-')
		return operand1 - operand2;
	if (token[0] == '*')
		return operand1 * operand2;
	if (token[0] == '/')
		return operand1 / operand2;
	return 0;
}