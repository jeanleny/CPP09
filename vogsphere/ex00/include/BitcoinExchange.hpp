#ifndef BTC_H
# define BTC_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <exception>

class NoDataException : public std::exception
{
	public :
		const char *what () const throw();
};

class NoSuchFileException : public std::exception
{
	public :
		const char *what () const throw();
};

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


typedef struct s_dates
{
	int	year;
	int	month;
	int day;
	int	aYear;
	int	aMonth;
	int aDay;
} t_dates;

typedef struct s_files
{
	std::map<std::string, float> data;
	std::map<std::string, float> input;
} t_files;

s_dates	setDates(std::string year,std::string month,std::string day);
s_files						setfiles();
bool 						wrongDateFormat(std::string date);
bool 						isValidDay(std::string day);
bool 						isValidMonth(std::string month);
bool 						isValidYear(std::string year);
bool 						checkDayLogic(s_dates dates);
std::map<std::string,float> createCsvContent();
void convertInput(char *input, s_files files);

#endif
