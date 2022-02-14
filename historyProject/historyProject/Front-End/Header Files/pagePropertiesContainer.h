#pragma once
#include <SFML/Graphics.hpp>
#include <string>

struct PagePropertiesContainer
{
	std::string name;
	void (*initialize)();
	void (*destroy)();
	void (*draw)(sf::RenderWindow&);
	void (*selectTextBox)(sf::Event&, std::string&);
	bool (*handleEvents)(sf::Event&, std::string&);
};