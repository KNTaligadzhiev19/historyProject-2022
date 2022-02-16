#include "../Header Files/eventOptions.h"

void searchForEvent(NODE*& head, std::string& text, std::vector<sf::Text>& eventsAfterSearch)
{
	sf::Text textBox;

	while (head->next != NULL)
	{
		if (head->title == text)
		{
			text = head->title + " - " + head->date;
			textBox.setString(text);
			eventsAfterSearch.push_back(textBox);
		}

		head = head->next;
	}
}

void modifyTextAfterEdit(NODE*& head, std::string& titleStr, std::string& dateStr, std::string& descriptionStr, std::string str)
{
	while (head->next != NULL)
	{
		if (head->title == str)
		{
			head->title = titleStr;
			head->date = dateStr;
			head->description = descriptionStr;
			break;
		}

		head = head->next;
	}
}