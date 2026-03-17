#include <Exception.hpp>

const	char* WrongFileException::what() const throw()
{
	return ("The format is wrong");
}

const	char* WrongYearException::what() const throw()
{
	return ("The year is erroneous");
}

const	char* WrongMonthException::what() const throw()
{
	return ("The month is erroneous");
}

const	char* WrongDayException::what() const throw()
{
	return ("The day is erroneous");
}

const	char* WrongValueException::what() const throw()
{
	return ("The Value must be either a float or an integer between 0 and 1000");
}
