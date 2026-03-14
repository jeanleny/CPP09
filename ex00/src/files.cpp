#include <btc.h>



std::map<std::string,float> createCsvContent()
{
	std::map<std::string, float> mapContent;
	std::ifstream	f("data.csv");
	std::string 	line;
	std::string 	date;
	float			value;
	while (getline(f, line))
	{
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
	return mapContent;
}

s_files	setfiles(void)
{
	s_files files;
	files.data = createCsvContent();
	//files.input = createInputContent();
	return (files);
}
