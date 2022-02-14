#pragma once
#include <iostream>
#include <fstream>

struct NODE
{
	std::string title = "";
	std::string date = "";
	std::string description = "";
	bool isEmpty = true;
	NODE* next = NULL;
	
	NODE() {}

	NODE(std::string& title, std::string& date, std::string& description);
};

void setDataToNodes(NODE*& head, std::string& title, std::string& date, std::string& description, std::fstream& eventInfo);

//void newElement(NODE* head, std::string& title, std::string& date, std::string& description);