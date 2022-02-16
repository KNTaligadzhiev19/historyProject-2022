#pragma once
#include "../Header Files/startProgram.h"

void timelineEvents(sf::Event userEvent, CURRENT_PAGE& pageFlag, SELECTED_TEXT_BOX& textBoxFlag,
	sf::Texture& currentPageTexture, std::fstream& eventInfo, NODE* head, std::vector<sf::Text>& events,
	std::vector<std::string>& eventTitle);