#ifndef BTC_H
# define BTC_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <Exception.hpp>

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

s_files						setfiles();
bool 						wrongDateFormat(std::string date);
bool 						isValidDay(std::string day);
bool 						isValidMonth(std::string month);
bool 						isValidYear(std::string year);
std::map<std::string,float> createCsvContent();
std::map<std::string,float> createInputContent();

#endif
