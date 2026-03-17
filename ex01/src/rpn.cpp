#include <rpn.h>

void ftRpn(char *input)
{
	std::stack<int> iStack;
	for (size_t i = 0; i < strlen(input); i++)
	{
		if (isdigit(input[i]))
		{
			int	value = input[i] - 48;
			iStack.push(value);
		}
		else if (isToken(input[i]))
		{
			if (iStack.size() >= 2)
			{
				int right = iStack.top();
				iStack.pop();
				int left = iStack.top();
				iStack.pop();
				if (input[i] == '-')
					iStack.push(left - right);
				if (input[i] == '+')
					iStack.push(left + right);
				if (input[i] == '/')
					iStack.push(left / right);
				if (input[i] == '*')
					iStack.push(left * right);
			}
		}
	}
	std::cout << iStack.top() << std::endl;
}
