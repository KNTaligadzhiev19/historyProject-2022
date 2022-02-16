#pragma once
#include "../Header Files/startProgram.h"

void addAnEventMenuEvents(sf::Event userEvent, CURRENT_PAGE& pageFlag, SELECTED_TEXT_BOX& textBoxFlag,
    sf::Texture& currentPageTexture, NODE* head, std::fstream& eventInfo, sf::Text& title, sf::Text& date, sf::Text& description,
    std::string& titleStr, std::string& dateStr, std::string& descriptionStr);