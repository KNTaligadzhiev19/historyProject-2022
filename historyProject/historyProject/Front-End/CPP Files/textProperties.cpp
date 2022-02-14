#include "../Header Files/textProperties.h"
#include <iostream>
#include <vector>

//std::vector<sf::Text> initText(int numberOfFields)
//{
//	std::vector<sf::Text>* textFields = new std::vector<sf::Text>;
//
//	for (size_t i = 0; i < numberOfFields; i++)
//	{
//		sf::Text* field = new sf::Text;
//		textFields->push_back(*field);
//	}
//
//	return *textFields;
//}
//
//void setFontToText(sf::Font font, std::vector<sf::Text>& fields)
//{
//	for (size_t i = 0; i < fields.size(); i++)
//	{
//		fields[i].setFont(font);
//	}
//}
//
//void setSizeToText(int sizeOfText, std::vector<sf::Text>& fields)
//{
//	for (size_t i = 0; i < fields.size(); i++)
//	{
//		fields[i].setCharacterSize(sizeOfText);
//	}
//}
//
//void setColorToText(sf::Color color, std::vector<sf::Text>& fields)
//{
//	for (size_t i = 0; i < fields.size(); i++)
//	{
//		fields[i].setFillColor(color);
//	}
//}
//
//void setPositionToText(int positions[], std::vector<sf::Text>& fields)
//{
//	for (size_t i = 0; i < fields.size(); i++)
//	{
//		fields[i].setPosition(positions[i], positions[i + 1]);
//	}
//}
//
//std::vector<sf::Text> setProperties(int numberOfFields = 0, int sizeOfChars = 0, sf::Color color = sf::Color::Black, int positions[] = {0})
//{
//	sf::Font font;
//	font.loadFromFile("images and fonts/alkesregular.ttf");
//	std::vector<sf::Text> fields = initText(numberOfFields);
//	setFontToText(font, fields);
//	setSizeToText(sizeOfChars, fields);
//	setColorToText(color, fields);
//	setPositionToText(positions, fields);
//	fields[0].setString("Test massage");
//
//	return fields;
//}