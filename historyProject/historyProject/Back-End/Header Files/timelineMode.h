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

namespace firstAndLastNodes
{
	static NODE* Head = new NODE;
	static NODE* Tail = new NODE;
};

void setDataToNodes(NODE& Head, std::string& title, std::string& date, std::string& description);