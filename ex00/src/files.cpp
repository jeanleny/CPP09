#include <btc.h>

std::map<std::string,float> createInputContent(char *input, s_files files)
{
	std::map<std::string, float> mapContent;
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
		mapContent[date] = value;
		std::cout << "input content " << mapContent[date] << std::endl;
		std::cout << "value : " << files.data[date] << std::endl;
	}
	f.close();
	return (mapContent);
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

s_files	setfiles(char *input)
{
	s_files files;
	files.data = createCsvContent();
	files.input = createInputContent(input, files);
	
	return (files);
}
