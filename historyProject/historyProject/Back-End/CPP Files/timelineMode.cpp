#include <iostream>
#include "../Header Files/timelineMode.h"

void setDataToNodes(NODE& Head, std::string& title, std::string& date, std::string& description)
{
	for (size_t i = 0; i < 1; i++)
	{
		if (Head.isEmpty)
		{
			Head.title = title;
			Head.date = date;
			Head.description = description;
			Head.isEmpty = false;
		}
	}

	std::cout << Head.title << " " << Head.date << " " << Head.description << " " << Head.isEmpty << std::endl;
}