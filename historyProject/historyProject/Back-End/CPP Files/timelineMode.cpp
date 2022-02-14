#include <iostream>
#include "../header Files/timelineMode.h"

void newElement(NODE& head)
{
	NODE* newElement = new NODE;

	newElement->next = NULL;

	head.next = newElement;
}

void setDataToNodes(NODE& head, std::string& title, std::string& date, std::string& description)
{

	if (head.next == NULL)
	{
		head.title = title;
		head.date = date;
		head.description = description;
		head.isEmpty = false;
		std::cout << "Title: " << head.title << " | Date: " << head.date << " | Description: " << head.description << " | isEmpty: " << head.isEmpty << " | Adress: " << &head << std::endl;

		newElement(head);
	}
	else
	{
		head = *head.next;
		setDataToNodes(head, title, date, description);
	}
}