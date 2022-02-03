#include <iostream>

struct NODE
{
	std::string title = "";
	std::string date = "";
	std::string description = "";
	bool isEmpty = true;
	NODE* next = NULL;
};