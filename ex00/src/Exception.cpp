#include <Exception.hpp>

const	char* WrongFileException::what() const throw()
{
	return ("The file is wrong");
}
