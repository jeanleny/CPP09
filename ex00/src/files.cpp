#include <btc.h>

std::string	datesLoop(s_files files, s_dates date)
{
	std::map<std::string, float>::iterator it;
	for (it = files.data.begin(); it != files.data.end(); it++)
	{
		std::string year = it->first.substr(0, 4);
		std::string month = it->first.substr(5, 2);
		std::string day = it->first.substr(8, 2);
		s_dates dataDates = setDates(year, month, day);
		if (dataDates.day >= date.day && dataDates.month >= date.month && dataDates.year >= date.year)
			return ((--it)->first);
	}
	return ("");
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

void convertInput(char *input, s_files files)
{
	std::ifstream	f(input);
	std::string 	line;
	std::string 	date;
	float			value;

	while (getline(f, line))
	{
		size_t	pos = line.find("|");
		if (pos == std::string::npos)
		{
			std::cout << "Bad input" << std::endl;
			continue ;
		}
		if (pos != 0)
			pos--;
		date = line.substr(0, pos);
		try
		{
			wrongDateFormat(date);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		pos++;
		value = atof(line.substr(pos + 1).c_str());
		if (value < 0 || value > 1000)
		{
			std::cout << "The Value must be either a float or an integer between 0 and 1000" << std::endl;
			continue ;
		}
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
