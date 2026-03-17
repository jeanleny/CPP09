#include <btc.h>

int		getActualYear()
{
	std::time_t time = std::time(NULL);
	struct tm current_time = *std::localtime(&time);

	return (current_time.tm_year + 1900);
}

int		getActualMonth()
{
	std::time_t time = std::time(NULL);
	struct tm current_time = *std::localtime(&time);

	return (current_time.tm_mon + 1);
}

int		getActualDay()
{
	std::time_t time = std::time(NULL);
	struct tm current_time = *std::localtime(&time);

	return (current_time.tm_mday);
}

bool	strIsDigit(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool isValidYear(std::string year, s_dates dates)
{
	if (!strIsDigit(year))
		return (false);
	if (dates.year < 2009 || dates.year > dates.aYear)
		return (false);
	return (true);
}

bool isValidMonth(std::string month,s_dates dates)
{
	if (!strIsDigit(month))
		return (false);
	if (dates.year == getActualYear())
	{
		if (dates.month < 1 || dates.month > dates.aMonth)
			return (false);
	}
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
	if (dates.year == dates.aYear)
	{
		if (dates.month == dates.aMonth)
			if (dates.day > dates.aDay)
				return (false);
	}
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
	dates.aYear = getActualYear();
	dates.aMonth = getActualMonth();
	dates.aDay = getActualDay();

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
		throw WrongFileException();
	return (false);
}
