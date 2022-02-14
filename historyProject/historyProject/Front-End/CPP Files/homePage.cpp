//#include "../Header Files/homePage.h"
//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//struct HomePage
//{
//	sf::Texture* background;
//	sf::Sprite* backgroundSprite;
//} homePageProperties;
//
//void initializeHomePage()
//{
//	std::cout << "Initializing home page\n";
//
//	homePageProperties.background = new sf::Texture();
//	if (!homePageProperties.background->loadFromFile("Images and fonts/Home-page.png"))
//	{
//		//create basic screen
//	}
//
//	homePageProperties.backgroundSprite = new sf::Sprite(*homePageProperties.background);
//}
//
//void destroyHomePage()
//{
//	std::cout << "Destroying home page\n";
//
//	delete homePageProperties.backgroundSprite;
//	delete homePageProperties.background;
//}
//
//
//void drawHomePage(sf::RenderWindow& window)
//{
//	window.draw(*homePageProperties.backgroundSprite);
//}
//
//
//bool handleHomePageEvents(sf::Event& userEvent, std::string& nextPage)
//{
//	switch (userEvent.type)
//	{
//	case sf::Event::MouseButtonPressed:
//	{
//		std::cout << userEvent.mouseButton.x << ", " << userEvent.mouseButton.y << "\n";
//
//		if (userEvent.mouseButton.x >= 180 && userEvent.mouseButton.x <= 625 &&
//			userEvent.mouseButton.y >= 400 && userEvent.mouseButton.y <= 510)
//		{
//			nextPage = "Timeline Page";
//			
//		}
//
//		if (userEvent.mouseButton.x >= 180 && userEvent.mouseButton.x <= 625 &&
//			userEvent.mouseButton.y >= 720 && userEvent.mouseButton.y <= 820)
//		{
//			return false;
//		}
//	}; break;
//
//	default:
//		break;
//	}
//
//	return true;
//}
//
//PagePropertiesContainer* createHomePage()
//{
//	PagePropertiesContainer* propertiesContainer = new PagePropertiesContainer();
//
//	propertiesContainer->name = "Main menu";
//	propertiesContainer->initialize = &initializeHomePage;
//	propertiesContainer->destroy = &destroyHomePage;
//	propertiesContainer->handleEvents = &handleHomePageEvents;
//	propertiesContainer->draw = &drawHomePage;
//
//	return propertiesContainer;
//}