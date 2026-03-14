#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

#include <exception>

class WrongFileException : public std::exception
{
	public :
		const char *what () const throw();
};

#endif
