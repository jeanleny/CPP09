#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

#include <exception>

class WrongFileException : public std::exception
{
	public :
		const char *what () const throw();
};

class WrongYearException : public std::exception
{
	public :
		const char *what () const throw();
};

class WrongMonthException : public std::exception
{
	public :
		const char *what () const throw();
};

class WrongDayException : public std::exception
{
	public :
		const char *what () const throw();
};

class WrongValueException : public std::exception
{
	public :
		const char *what () const throw();
};

#endif
