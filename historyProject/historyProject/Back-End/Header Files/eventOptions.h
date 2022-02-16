#pragma once
#include "../../Front-End/Header Files/startProgram.h"

void searchForEvent(NODE*& head, std::string& text, std::vector<sf::Text>& eventsAfterSearch);

void modifyTextAfterEdit(NODE*& head, std::string& titleStr, std::string& dateStr, std::string& descriptionStr, std::string str);