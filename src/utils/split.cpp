/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/12/2024
*/
#include <vector>
#include <string>

std::vector<std::string>	split(const std::string &str, const std::string &d)
{
	size_t	pos = 0;
	size_t	find = str.find(d);
	std::vector<std::string> ret;

	if (find == std::string::npos)
	{
		ret.emplace_back(str);
		return (ret);
	}
	while (find != std::string::npos)
	{
		ret.emplace_back(str.substr(pos, find - pos));
		pos = find + d.length();
		find = str.find(d, pos);
	}
	ret.emplace_back(str.substr(pos));
	return (ret);
}

void	split(std::vector<std::string> &vect, const std::string &str, const std::string &d)
{
	size_t	pos = 0;
	size_t	find = str.find(d);

	if (find == std::string::npos)
	{
		vect.emplace_back(str);
	}
	while (find != std::string::npos)
	{
		vect.emplace_back(str.substr(pos, find - pos));
		pos = find + d.length();
		find = str.find(d, pos);
	}
	vect.emplace_back(str.substr(pos));
}
