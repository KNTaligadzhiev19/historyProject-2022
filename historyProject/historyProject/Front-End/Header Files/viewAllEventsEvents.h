#pragma once
#include "../Header Files/startProgram.h"

void viewAllEventsEvents(sf::Event userEvent, CURRENT_PAGE& pageFlag, SELECTED_TEXT_BOX& textBoxFlag, sf::Texture& currentPageTexture,
	std::string &search, sf::Text& serachBar, NODE*& head, std::vector<sf::Text>& eventsAfterSearch);