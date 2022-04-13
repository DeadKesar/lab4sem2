#pragma once
#include <string>


class PostAdres
{
	int index;
	const std::string country;
	const std::string city;
	const std::string street;
	const std::string korpus;
	const std::string stroenie;
	const std::string home;

public:
	PostAdres(int index, const std::string country, const std::string city, const std::string street, const std::string korpus, const std::string stroenie, const std::string home);
	bool equal(PostAdres adr);
	std::string ToString()
	{
		return std::to_string(index) + " " + country + " " + city + " " + street + " " + korpus + " " + stroenie + " " + home;
	}
	int compare(PostAdres adr);

};

