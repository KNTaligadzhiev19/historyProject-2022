#include "../Header Files/viewAllEventsPage.h"
#include "../Header Files/timelineMode.h"
#include "../../Front-End/Header Files/startProgram.h"

void writeDataToNode(NODE*& head, std::string& title, std::string& date, std::string& description)
{
	NODE* tail = getTail(head);

	newElement(tail, title, date, description);
}

void extractInfo(std::string line, NODE*& head)
{
	std::string title, date, description;
	int i = 0;

	for (; i < line.size(); i++)
	{
		if (line[i] != '#')
		{
			title += line[i];
		}
		else
		{
			break;
		}
	}

	i++;

	for (; i < line.size(); i++)
	{
		if (line[i] != '#')
		{
			date += line[i];
		}
		else
		{
			break;
		}
	}

	i++;

	for (; i < line.size(); i++)
	{
		if (line[i] != '#')
		{
			description += line[i];
		}
		else
		{
			break;
		}
	}

	writeDataToNode(head, title, date, description);
}

void setDataToVectors(NODE* head, std::vector<sf::Text>& events, std::vector<std::string>& eventTitles)
{
	sf::Text text;
	std::string title;

	while (head->next != NULL)
	{
		title = head->title + " - " + head->date;
		eventTitles.push_back(title);
		text.setString(title);
		events.push_back(text);
		head = head->next;
	}
}

void showEvent(std::fstream& eventInfo, NODE*& head, std::vector<sf::Text>& events, std::vector<std::string>& eventTitles)
{
	eventInfo.open("eventInfo.txt", std::ios::in | std::ios::app);

	if (eventInfo.is_open())
	{
		std::string line;
		while (std::getline(eventInfo, line))
		{
			extractInfo(line, head);
		}
		eventInfo.close();
	}
	setDataToVectors(head, events, eventTitles);
	display(head);
}
