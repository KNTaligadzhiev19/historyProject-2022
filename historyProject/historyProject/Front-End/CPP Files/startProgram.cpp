#include <SFML/Graphics.hpp>
#include "../Header Files/startProgram.h"
#include "../Header Files/addAnEventForm.h"
#include "../Header Files/timelineMenu.h"
#include "../../Back-End/Header Files/timelineMode.h"
#include "../Header Files/textBox.h"
#include <iostream>

void switchPages(sf::RenderWindow& window, sf::Event& userEvent, sf::Texture& currentPageTexture, CURRENT_PAGE& pageFlag, 
    SELECTED_TEXT_BOX& textBoxFlag)
{
    switch (userEvent.type)
    {
    case sf::Event::Closed: window.close();
        break;

    case sf::Event::MouseButtonPressed:
    {
        if ((userEvent.mouseButton.x >= 170 && userEvent.mouseButton.x <= 625) &&
            (userEvent.mouseButton.y >= 400 && userEvent.mouseButton.y <= 510) &&
            pageFlag.homeMenu == true)
        {
            std::cout << "Enter timeline menu \n";
            currentPageTexture.loadFromFile("Images and fonts/Timeline menu.png");

            pageFlag.homeMenu = false;
            pageFlag.addAnEventMenu = false;
            pageFlag.timelineMenu = true;

        }
        else if ((userEvent.mouseButton.x >= 170 && userEvent.mouseButton.x <= 625) &&
            (userEvent.mouseButton.y >= 340 && userEvent.mouseButton.y <= 450) &&
            pageFlag.timelineMenu == true)
        {
            std::cout << "Enter add an event option \n";

            currentPageTexture.loadFromFile("Images and fonts/Add an event form.png");

            pageFlag.addAnEventMenu = true;
            pageFlag.timelineMenu = false;
            pageFlag.homeMenu = false;

        }
        else if ((userEvent.mouseButton.x >= 20 && userEvent.mouseButton.x <= 172) &&
            (userEvent.mouseButton.y >= 800 && userEvent.mouseButton.y <= 880) &&
            pageFlag.timelineMenu == true)
        {
            std::cout << "Back to main menu \n";
            currentPageTexture.loadFromFile("Images and fonts/Home-page.png");

            pageFlag.homeMenu = true;
            pageFlag.timelineMenu = false;
            pageFlag.addAnEventMenu = false;
        }

        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 195 && userEvent.mouseButton.x <= 500) &&
            (userEvent.mouseButton.y >= 225 && userEvent.mouseButton.y <= 260))
        {
            textBoxFlag.titleTextBox = true;
            textBoxFlag.dateTextBox = false;
            textBoxFlag.descriptionTextBox = false;
            textBoxProperties::titleBox.setPosition(210, 230);

        }
        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 195 && userEvent.mouseButton.x <= 400) &&
            (userEvent.mouseButton.y >= 325 && userEvent.mouseButton.y <= 360))
        {
            textBoxFlag.titleTextBox = false;
            textBoxFlag.dateTextBox = true;
            textBoxFlag.descriptionTextBox = false;
            textBoxProperties::dateBox.setPosition(210, 330);

        }
        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 195 && userEvent.mouseButton.x <= 475) &&
            (userEvent.mouseButton.y >= 425 && userEvent.mouseButton.y <= 520))
        {
            textBoxFlag.titleTextBox = false;
            textBoxFlag.dateTextBox = false;
            textBoxFlag.descriptionTextBox = true;
            textBoxProperties::descriptionBox.setPosition(210, 430);

        }
        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 195 && userEvent.mouseButton.x <= 300) &&
            (userEvent.mouseButton.y >= 700 && userEvent.mouseButton.y <= 750))
        {
            setDataToNodes(*firstAndLastNodes::Head, textBoxProperties::enteredTextForTitleBox, textBoxProperties::enteredTextForDateBox,
                textBoxProperties::enteredTextForDescriptionBox);
            textBoxProperties::isDeleted = true;

            //delete textBoxProperties::titleBox;
            //delete textBoxProperties::dateBox;
            //delete textBoxProperties::descriptionBox;

            currentPageTexture.loadFromFile("Images and fonts/Timeline menu.png");

            pageFlag.homeMenu = false;
            pageFlag.addAnEventMenu = false;
            pageFlag.timelineMenu = true;

        }
        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 320 && userEvent.mouseButton.x <= 425) &&
            (userEvent.mouseButton.y >= 700 && userEvent.mouseButton.y <= 750))
        {
            currentPageTexture.loadFromFile("Images and fonts/Timeline menu.png");

            pageFlag.homeMenu = false;
            pageFlag.addAnEventMenu = false;
            pageFlag.timelineMenu = true;
        }

        break;
    }

    default:
        break;
    }
}

void selectTextBox(sf::RenderWindow& window, sf::Event& userEvent, SELECTED_TEXT_BOX& textBoxFlag)
{
    switch (userEvent.type)
    {
    case sf::Event::TextEntered:
        if (userEvent.text.unicode < 128 && userEvent.text.unicode != 13 &&
            userEvent.text.unicode != 8 && textBoxFlag.titleTextBox == true)
        {
            textBoxProperties::enteredTextForTitleBox += static_cast<char>(userEvent.text.unicode);
            textBoxProperties::titleBox.setString(textBoxProperties::enteredTextForTitleBox);

        }
        else if (userEvent.text.unicode < 128 && userEvent.text.unicode != 13 &&
            userEvent.text.unicode != 8 && textBoxFlag.dateTextBox == true)
        {
            textBoxProperties::enteredTextForDateBox += static_cast<char>(userEvent.text.unicode);
            textBoxProperties::dateBox.setString(textBoxProperties::enteredTextForDateBox);

        }
        else if (userEvent.text.unicode < 128 && userEvent.text.unicode != 13 &&
            userEvent.text.unicode != 8 && textBoxFlag.descriptionTextBox == true)
        {
            textBoxProperties::enteredTextForDescriptionBox += static_cast<char>(userEvent.text.unicode);
            textBoxProperties::descriptionBox.setString(textBoxProperties::enteredTextForDescriptionBox);
        }

        break;
    default:
        break;
    }
}


void startProgram()
{
    CURRENT_PAGE pageFlag;
    SELECTED_TEXT_BOX textBoxFlag;

    sf::RenderWindow window(sf::VideoMode(800, 900), "Historya", sf::Style::Close);
    window.setFramerateLimit(30);

    sf::Texture* currentPageTexture = new sf::Texture;
    currentPageTexture->loadFromFile("Images and fonts/Home-page.png");

    sf::Sprite* currentPageSprite = new sf::Sprite;
    currentPageSprite->setTexture(*currentPageTexture);

    sf::Font font;
    font.loadFromFile("images and fonts/alkesregular.ttf");

    textBoxProperties::titleBox.setFont(font);
    textBoxProperties::dateBox.setFont(font);
    textBoxProperties::descriptionBox.setFont(font);

    textBoxProperties::titleBox.setCharacterSize(20);
    textBoxProperties::dateBox.setCharacterSize(20);
    textBoxProperties::descriptionBox.setCharacterSize(20);

    textBoxProperties::titleBox.setFillColor(sf::Color::Black);
    textBoxProperties::dateBox.setFillColor(sf::Color::Black);
    textBoxProperties::descriptionBox.setFillColor(sf::Color::Black);


    while (window.isOpen())
    {
        sf::Event userEvent;

        while (window.pollEvent(userEvent))
        {
            switchPages(window, userEvent, *currentPageTexture, pageFlag, textBoxFlag);

            selectTextBox(window, userEvent, textBoxFlag);
        }


       

        window.clear();

        window.draw(*currentPageSprite);

        if (!textBoxProperties::isDeleted)
        {
            window.draw(textBoxProperties::titleBox);
            window.draw(textBoxProperties::dateBox);
            window.draw(textBoxProperties::descriptionBox);
        }
        
        window.display();
    }

    delete currentPageTexture;
    delete currentPageSprite;
}