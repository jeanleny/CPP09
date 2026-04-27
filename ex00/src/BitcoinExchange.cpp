#include <BitcoinExchange.hpp>

bool	strIsDigit(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	isAnteBtc(s_dates dates)
{
	if (dates.year < 2009)
		return (true);
	if (dates.year == 2009 && dates.day == 01 && dates.month == 01)
		return (true);
	return (false);
}

bool isValidYear(std::string year, s_dates dates)
{
	if (!strIsDigit(year))
		return (false);
	if (isAnteBtc(dates))
		return (false);
	return (true);
}

bool isValidMonth(std::string month,s_dates dates)
{
	if (!strIsDigit(month))
		return (false);
	else
	{
		if (dates.month < 1 || dates.month > 12)
			return (false);
	}
	return (true);
};

bool isValidDay(std::string day, s_dates dates)
{
	if (!strIsDigit(day))
		return (false);
	if (dates.day < 1 || dates.day > 31)
		return (false);
	else
	{
		if (!checkDayLogic(dates))
			return (false);
	}
	return (true);
};

bool checkDayLogic(s_dates dates)
{
	if (dates.month == 2)
	{
		if (dates.day == 29 && dates.year % 4 != 0)
			return (false);
	}
	else if (dates.month <= 7)
	{
		if (dates.month % 2 == 0 && dates.day > 30)
			return (false);
	}
	else if (dates.month >= 8)
	{
		if (dates.month % 2 != 0 && dates.day > 30)
			return (false);
	}
	return (true);
}

s_dates	setDates(std::string year,std::string month,std::string day)
{
	s_dates dates;
	dates.year = atoi(year.c_str());
	dates.month = atoi(month.c_str());
	dates.day = atoi(day.c_str());

	return (dates);
}

bool wrongDateFormat(std::string date)
{
	if (date.length() == 10)
	{
		std::string year = date.substr(0, 4);
		std::string month = date.substr(5, 2);
		std::string day = date.substr(8, 2);
		s_dates dates = setDates(year, month, day);
		if (!isValidYear(year, dates))
			throw WrongYearException();
		if (!isValidMonth(month, dates))
			throw WrongMonthException();
		if (!isValidDay(day, dates))
			throw WrongDayException();
	}
	else
		return (true);
	return (false);
}

const	char* NoDataException::what() const throw()
{
	return ("The data.csv doesn't exist");
}

const	char* NoSuchFileException::what() const throw()
{
	return ("The file doesn't exist");
}

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

std::string	datesLoop(s_files files, s_dates date)
{
	bool	first = true;
	std::map<std::string, float>::iterator it;
	std::map<std::string, float>::iterator last = files.data.end();
	for (it = files.data.begin(); it != files.data.end(); it++)
	{
		std::string year = it->first.substr(0, 4);
		std::string month = it->first.substr(5, 2);
		std::string day = it->first.substr(8, 2);
		s_dates dataDates = setDates(year, month, day);
		if (dataDates.day >= date.day && dataDates.month >= date.month && dataDates.year >= date.year)
		{
			if (!first)
				--it;
			return ((it)->first);
		}
		first = false;
	}
	return ((--last)->first);
}

std::string getClosestDate(s_files files, std::string date)
{
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	s_dates dates = setDates(year, month, day);
	return (datesLoop(files, dates));
}

void	displayResult(float value, s_files files, std::string date)
{
	std::string	closest;
	try
	{
		files.data.at(date);
		std::cout << date << " => " << value << " = " << value * files.data[date] << std::endl;
	}
	catch(std::exception &e)
	{
		closest = getClosestDate(files, date);
		std::cout << date << " => " << value << " = " << value * files.data[closest] << std::endl;
	}
}

bool	validValue(std::string value)
{
	bool dot = false;
	bool min = false;
	bool plu = false;
	if (value.size() <= 0)
		return (false);
	for (size_t i = 0; i < value.size(); i++)
	{
		if (!isdigit(value[i]))
		{
			if (value[i] == '.' && !dot)
			{
				dot = true;
				continue ;
			}
			if (value[i] == '+' && !plu)
			{
				plu = true;
				continue ;
			}
			if (value[i] == '-' && !min)
			{
				min = true;
				continue ;
			}
			return (false);
		}
	}
	return (true);
}

bool	checkValue(float &value, size_t pos , std::string line)
{
	pos ++;
	while (line[pos] && isspace(line[pos]))
		pos++;
	std::string strValue = line.substr(pos).c_str();
	if (!validValue(strValue))
	{
		std::cout << "values must be numeric" << std::endl;
		return (false);
	}
	value = atof(line.substr(pos).c_str());
	if (value < 0 || value > 1000)
	{
		std::cout << "The Value must be either a float or an integer between 0 and 1000" << std::endl;
		return (false);
	}
	return (true);
}

void convertInput(char *input, s_files files)
{
	std::ifstream	f(input);
	std::string 	line;
	std::string 	date;
	float			value;

	if (f.fail())
		throw NoSuchFileException();
	while (getline(f, line))
	{
		size_t	pos = line.find("|");
		if (pos == std::string::npos)
		{
			std::cout << "The input must be \"date | value\" formatted" << std::endl;
			continue ;
		}
		if (pos != 0)
			pos--;
		date = line.substr(0, pos);
		try
		{
			if (wrongDateFormat(date))
				continue ;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			continue ;
		}
		pos++;
		if (!checkValue(value, pos, line))
 			continue ;
		files.input[date] = value;
		displayResult(value, files, date);
	}
	f.close();
}

std::map<std::string,float> createCsvContent()
{
	std::map<std::string, float> mapContent;
	std::ifstream	f("data.csv");
	std::string 	line;
	std::string 	date;
	float			value;
	bool			first = true;
	if (f.fail())
		throw NoDataException();
	while (getline(f, line))
	{
		if (first == true)
		{
			first = false;
			continue;
		}
		size_t	pos = line.find(",");
		if (pos == std::string::npos)
			throw WrongFileException();
		date = line.substr(0, pos);
		if (wrongDateFormat(date))
			throw WrongFileException();
		value = atof(line.substr(pos + 1).c_str());
		mapContent[date] = value;
	}
	f.close();
	return (mapContent);
}

s_files	setfiles()
{
	s_files files;
	files.data = createCsvContent();
	
	return (files);
}
