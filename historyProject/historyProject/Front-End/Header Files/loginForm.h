#pragma once
#include "../Header Files/startProgram.h"

void loginEvents(sf::Event& userEvent, CURRENT_PAGE& pageFlag, SELECTED_TEXT_BOX& textBoxFlag,
	sf::Texture& currentPageTexture, std::fstream& userInfo, std::string& username, std::string& password,
	sf::Text& usernameBox, sf::Text& passwordBox);