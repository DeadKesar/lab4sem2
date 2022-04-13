#include "PostAdres.h"


bool PostAdres::equal(PostAdres adr)
{
	if (this->index != adr.index)
		return false;
	if (this->country != adr.country)
		return false;
	if (this->city!= adr.city)
		return false;
	if (this->street != adr.street)
		return false;
	if (this->korpus != adr.korpus)
		return false;
	if (this->stroenie != adr.stroenie)
		return false;
	if (this->home != adr.home)
		return false;
	return true;
}
int PostAdres::compare(PostAdres adr)
{
	if (this->index > adr.index)
		return 1;
	else if (this->index < adr.index)
		return -1;
	if (this->country > adr.country)
		return 1;
	else if (this->country < adr.country)
		return -1;
	if (this->city > adr.city)
		return 1;
	else if (this->city < adr.city)
		return -1;
	if (this->street > adr.street)
		return 1;
	else if (this->street < adr.street)
		return -1;
	if (this->korpus > adr.korpus)
		return 1;
	else if (this->korpus < adr.korpus)
		return -1;
	if (this->stroenie > adr.stroenie)
		return 1;
	else if (this->stroenie < adr.stroenie)
		return -1;
	if (this->home > adr.home)
		return 1;
	else if (this->home < adr.home)
		return -1;
	return 0;

}



PostAdres::PostAdres(const int index, const std::string country, const std::string city, const std::string street, const std::string korpus, const std::string stroenie, const std::string home)
	:index(index), country(country), city(city), street(street), korpus(korpus), stroenie(stroenie), home(home)
{}

