#pragma once
#include <iostream>

struct NODE
{
	std::string title = "";
	std::string date = "";
	std::string description = "";
	bool isEmpty = true;
	NODE* next = NULL;
};

void setDataToNodes(NODE& head, std::string& title, std::string& date, std::string& description);

//void newElement(NODE* head, std::string& title, std::string& date, std::string& description);