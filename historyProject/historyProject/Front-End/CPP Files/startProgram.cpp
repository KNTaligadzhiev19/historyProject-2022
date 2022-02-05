#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header Files/startProgram.h"
#include "../../Back-End/header Files/timelineMode.h"

void switchPages(sf::RenderWindow& window, sf::Event& userEvent, sf::Texture& currentPageTexture, CURRENT_PAGE& pageFlag,
    SELECTED_TEXT_BOX& textBoxFlag, NODE* head)
{
    switch (userEvent.type)
    {
    case sf::Event::Closed:
    {
        window.close();
        break;
    }

    case sf::Event::MouseButtonPressed:
    {
        if ((userEvent.mouseButton.x >= 170 && userEvent.mouseButton.x <= 625) &&
            (userEvent.mouseButton.y >= 400 && userEvent.mouseButton.y <= 510) && pageFlag.homeMenu == true)
        {
            std::cout << "Enter timeline menu \n";
            currentPageTexture.loadFromFile("Images and fonts/Timeline menu.png");
            pageFlag.homeMenu = false;
            pageFlag.timelineMenu = true;
            pageFlag.addAnEventMenu = false;
        }
        else if ((userEvent.mouseButton.x >= 20 && userEvent.mouseButton.x <= 172) &&
            (userEvent.mouseButton.y >= 800 && userEvent.mouseButton.y <= 880) && pageFlag.timelineMenu == true)
        {
            std::cout << "Back to main menu \n";
            currentPageTexture.loadFromFile("Images and fonts/Home-page.png");
            pageFlag.homeMenu = true;
            pageFlag.timelineMenu = false;
            pageFlag.addAnEventMenu = false;
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
            /*setDataToNodes(*head, textBoxProperties::enteredTextForTitleBox, textBoxProperties::enteredTextForDateBox,
                textBoxProperties::enteredTextForDescriptionBox);*/

            textBoxProperties::enteredTextForTitleBox = "";
            textBoxProperties::enteredTextForDateBox = "";
            textBoxProperties::enteredTextForDescriptionBox = "";

            textBoxProperties::titleBox.setString(textBoxProperties::enteredTextForTitleBox);
            textBoxProperties::dateBox.setString(textBoxProperties::enteredTextForDateBox);
            textBoxProperties::descriptionBox.setString(textBoxProperties::enteredTextForDescriptionBox);

            currentPageTexture.loadFromFile("Images and fonts/Timeline menu.png");

            pageFlag.homeMenu = false;
            pageFlag.addAnEventMenu = false;
            pageFlag.timelineMenu = true;

        }
        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 320 && userEvent.mouseButton.x <= 425) &&
            (userEvent.mouseButton.y >= 700 && userEvent.mouseButton.y <= 750))
        {
            textBoxProperties::enteredTextForTitleBox = "";
            textBoxProperties::enteredTextForDateBox = "";
            textBoxProperties::enteredTextForDescriptionBox = "";

            textBoxProperties::titleBox.setString(textBoxProperties::enteredTextForTitleBox);
            textBoxProperties::dateBox.setString(textBoxProperties::enteredTextForDateBox);
            textBoxProperties::descriptionBox.setString(textBoxProperties::enteredTextForDescriptionBox);

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

std::string deleteCharFromText(std::string enteredText)
{
    std::string processedText;

    for (size_t i = 0; i < enteredText.size() - 1; i++)
    {
        processedText += enteredText[i];
    }

    return processedText;
}

void selectTextBox(sf::RenderWindow& window, sf::Event& userEvent, SELECTED_TEXT_BOX& textBoxFlag)
{
    switch (userEvent.type)
    {
    case sf::Event::TextEntered:
        if (userEvent.text.unicode < 128 && textBoxFlag.titleTextBox == true)
        {
            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
            {
                textBoxProperties::enteredTextForTitleBox += static_cast<char>(userEvent.text.unicode);
                textBoxProperties::titleBox.setString(textBoxProperties::enteredTextForTitleBox);
            }
            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForTitleBox.size() > 0)
            {
                textBoxProperties::enteredTextForTitleBox = deleteCharFromText(textBoxProperties::enteredTextForTitleBox);
                textBoxProperties::titleBox.setString(textBoxProperties::enteredTextForTitleBox);
            }
        }
        else if (userEvent.text.unicode < 128 && textBoxFlag.dateTextBox == true)
        {
            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
            {
                textBoxProperties::enteredTextForDateBox += static_cast<char>(userEvent.text.unicode);
                textBoxProperties::dateBox.setString(textBoxProperties::enteredTextForDateBox);
            }
            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForDateBox.size() > 0)
            {
                textBoxProperties::enteredTextForDateBox = deleteCharFromText(textBoxProperties::enteredTextForDateBox);
                textBoxProperties::dateBox.setString(textBoxProperties::enteredTextForDateBox);
            }
        }
        else if (userEvent.text.unicode < 128 && textBoxFlag.descriptionTextBox == true)
        {
            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
            {
                textBoxProperties::enteredTextForDescriptionBox += static_cast<char>(userEvent.text.unicode);
                textBoxProperties::descriptionBox.setString(textBoxProperties::enteredTextForDescriptionBox);
            }
            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForDescriptionBox.size() > 0)
            {
                textBoxProperties::enteredTextForDescriptionBox = deleteCharFromText(textBoxProperties::enteredTextForDescriptionBox);
                textBoxProperties::descriptionBox.setString(textBoxProperties::enteredTextForDescriptionBox);
            }
        }

        break;
    default:
        break;
    }
}

void startProgram(NODE* head)
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
            switchPages(window, userEvent, *currentPageTexture, pageFlag, textBoxFlag, head);
            selectTextBox(window, userEvent, textBoxFlag);
        }

        window.clear();

        window.draw(*currentPageSprite);
        window.draw(textBoxProperties::titleBox);
        window.draw(textBoxProperties::dateBox);
        window.draw(textBoxProperties::descriptionBox);

        window.display();
    }

    delete currentPageTexture;
    delete currentPageSprite;
}