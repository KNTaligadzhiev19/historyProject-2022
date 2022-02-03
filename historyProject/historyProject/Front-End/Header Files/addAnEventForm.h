#pragma once
#include "SFML/Graphics.hpp"
#include "../Header Files/startProgram.h"

void showTextOnWindow(sf::RenderWindow& window, sf::Event& userEvent, sf::Texture* currentPageTexture,
	CURRENT_PAGE& pageFlag, sf::Font& font, std::string& enteredTextContainer, sf::Text& text);