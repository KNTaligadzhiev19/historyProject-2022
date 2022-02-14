#include "../Header Files/loginForm.h"
//#include "../Header Files/textProperties.h"
#include <SFML/Graphics.hpp>
#include <iostream>

struct LoginPage
{
	sf::Texture* background;
	sf::Sprite* backgroundSprite;
} LoginPageProperties;

namespace enteredTextProperties
{
	sf::Text* username = new sf::Text;
    sf::Text* password = new sf::Text;

    std::string enteredUsername = "";
    std::string enteredPassword = "";
}

void initializeLoginPage()
{
	std::cout << "Initializing login page\n";

	LoginPageProperties.background = new sf::Texture();
	if (!LoginPageProperties.background->loadFromFile("Images and fonts/Login-form.png"))
	{
		//create basic screen
	}

	LoginPageProperties.backgroundSprite = new sf::Sprite(*LoginPageProperties.background);

	
}

void destroyLoginPage()
{
	std::cout << "Destroying login page\n";

	delete LoginPageProperties.backgroundSprite;
	delete LoginPageProperties.background;
}


void selectTextBox(sf::Event& userEvent, std::string& selectedField)
{
	switch (userEvent.type)
	{
	case sf::Event::TextEntered:
		if (userEvent.text.unicode < 128 && selectedField == "Username")
		{
			if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
			{
				enteredTextProperties::enteredUsername += static_cast<char>(userEvent.text.unicode);
				enteredTextProperties::username->setString(enteredTextProperties::enteredUsername);
			}
		}
		else if (userEvent.text.unicode < 128 && selectedField == "Password")
		{
			if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
			{
				enteredTextProperties::enteredPassword += static_cast<char>(userEvent.text.unicode);
				enteredTextProperties::password->setString(enteredTextProperties::enteredPassword);
			}
		}

		break;
	default:
		break;
	}
}

bool handleLoginPageEvents(sf::Event& userEvent, std::string& field)
{
	

	switch (userEvent.type)
	{
	case sf::Event::MouseButtonPressed:
	{
		std::cout << userEvent.mouseButton.x << " ~ " << userEvent.mouseButton.y << "\n";

		if (userEvent.mouseButton.x >= 80 && userEvent.mouseButton.x <= 720 &&
			userEvent.mouseButton.y >= 375 && userEvent.mouseButton.y <= 440)
		{	
			field = "Username";
			#pragma warning(suppress : 4996);
			enteredTextProperties::username->setColor(sf::Color::Black);
			enteredTextProperties::username->setCharacterSize(30);
			enteredTextProperties::username->setPosition(140, 390);


			selectTextBox(userEvent, field);

			std::cout << "daaaaa5";
			std::cout << enteredTextProperties::enteredUsername << std::endl;
			
			return true;
		}

		if (userEvent.mouseButton.x >= 80 && userEvent.mouseButton.x <= 720 &&
			userEvent.mouseButton.y >= 515 && userEvent.mouseButton.y <= 580)
		{
			field = "Password";
			#pragma warning(suppress : 4996);
			enteredTextProperties::password->setColor(sf::Color::Black);
			enteredTextProperties::password->setCharacterSize(30);
			enteredTextProperties::password->setPosition(140, 530);


			selectTextBox(userEvent, field);

			std::cout << "daaaaa51";
			std::cout << enteredTextProperties::enteredPassword << std::endl;

			return true;
		}

		if (userEvent.mouseButton.x >= 80 && userEvent.mouseButton.x <= 200 &&
			userEvent.mouseButton.y >= 600 && userEvent.mouseButton.y <= 700)
		{
			return true;
		}

		if (userEvent.mouseButton.x >= 360 && userEvent.mouseButton.x <= 500 &&
			userEvent.mouseButton.y >= 600 && userEvent.mouseButton.y <= 700)
		{
			if (!LoginPageProperties.background->loadFromFile("Images and fonts/Register-form.png"))
			{
				//create basic screen
				return false;
			}
			return true;
		}

	}; break;

	default:
		break;
	}

	return true;
}

void drawLoginPage(sf::RenderWindow& window)
{
	sf::Font font;
	font.loadFromFile("images and fonts/alkesregular.ttf");
	enteredTextProperties::username->setFont(font);
	enteredTextProperties::password->setFont(font);

	window.draw(*LoginPageProperties.backgroundSprite);

	if(enteredTextProperties::enteredUsername.size() > 0)
		window.draw(*enteredTextProperties::username);
		window.draw(*enteredTextProperties::password);
}



PagePropertiesContainer* createLoginPage()
{
	PagePropertiesContainer* propertiesContainer = new PagePropertiesContainer();

	propertiesContainer->name = "Login Page";
	propertiesContainer->initialize = &initializeLoginPage;
	propertiesContainer->destroy = &destroyLoginPage;
	propertiesContainer->handleEvents = &handleLoginPageEvents;
	propertiesContainer->selectTextBox = &selectTextBox;
	propertiesContainer->draw = &drawLoginPage;

	return propertiesContainer;
}