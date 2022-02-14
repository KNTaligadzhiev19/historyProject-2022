#include "../header Files/timelineMode.h"

NODE::NODE(std::string& title, std::string& date, std::string& description)
{
	this->title = title;
	this->date = date;
	this->description = description;
}

void newElement(NODE*& head, std::string& title, std::string& date, std::string& description)
{
	head->next = new NODE(title, date, description);
}


void display(NODE* head)
{
	while (head != NULL)
	{
		std::cout << head->title << std::endl;
		head = head->next;
	}
}

NODE* getTail(NODE* head)
{
	while (head->next != NULL)
	{
		head = head->next;
	}

	return head;
}

void writeDataIntoAFile(NODE*& head, std::fstream& eventInfo)
{
	eventInfo.open("eventInfo.txt", std::ios::out);
	if (!eventInfo.is_open())
	{
		std::cout << "Can not open userInfo.txt";
	}

	head = head->next;

	while (head != NULL)
	{
		eventInfo << head->title << "#" << head->date << "#" << head->description << "#" << "\n";
		head = head->next;
	}

	eventInfo.close();
}

void setDataToNodes(NODE*& head, std::string& title, std::string& date, std::string& description, std::fstream& eventInfo)
{
	NODE* tail = getTail(head);

	newElement(tail, title, date, description);

	display(head);

	writeDataIntoAFile(head, eventInfo);
}
