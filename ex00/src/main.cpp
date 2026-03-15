#include <btc.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			s_files files = setfiles(argv[1]);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (1);
}
