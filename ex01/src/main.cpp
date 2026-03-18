#include <RPN.hpp>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!validTokens(argv[1]))
		{
			std::cout << "Error" << std::endl;
			return (0);
		}
		try
		{
			ftRpn(argv[1]);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
