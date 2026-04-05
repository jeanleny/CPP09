#include <BitcoinExchange.hpp>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			s_files files = setfiles();
			convertInput(argv[1], files);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (1);
}
