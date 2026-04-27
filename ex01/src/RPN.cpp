#include <RPN.hpp>

const char* ErrorException::what() const throw()
{
	return ("Error");
}

bool	isToken(char a)
{
	return (a == '+' || a == '-' || a == '/' || a == '*');
}

bool validTokens(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]) && !isToken(str[i]) && !isspace(str[i]))
			return (false);
	}
	return (true);
}

void operation(char op, std::stack<int> &iStack)
{
	int right = iStack.top();
	iStack.pop();
	int left = iStack.top();
	iStack.pop();
	if (op == '-')
		iStack.push(left - right);
	if (op == '+')
		iStack.push(left + right);
	if (op == '/')
	{
		if (left == 0 || right == 0)
			throw ErrorException();
		iStack.push(left / right);
	}
	if (op == '*')
		iStack.push(left * right);
}

void ftRpn(char *input)
{
	std::stack<int> iStack;
	
	for (size_t i = 0; i < strlen(input); i++)
	{
		if (isdigit(input[i]) && (!input[i + 1] || isspace(input[i + 1])))
		{
			int	value = input[i] - 48;
			iStack.push(value);
			i++;
		}
		else if (isToken(input[i]) &&(!input[i + 1] || isspace(input[i + 1])))
		{
			if (iStack.size() >= 2)
				operation(input[i], iStack);
			else
				throw ErrorException();
		}
		else if (isspace(input[i]) && (isdigit(input[i + 1]) || isToken(input[i + 1])))
			continue ;
		else
			throw ErrorException();
	}
	if (iStack.size() > 1)
		throw ErrorException();
	std::cout << iStack.top() << std::endl;
}
