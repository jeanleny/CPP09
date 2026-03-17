#include <rpn.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!validTokens(argv[1]))
		{
			std::cout << "Error" << std::endl;
			return (0);
		}
		ftRpn(argv[1]);
	}
}
