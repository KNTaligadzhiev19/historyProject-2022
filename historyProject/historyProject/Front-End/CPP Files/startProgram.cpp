#include "../header Files/startProgram.h"
#include "../header Files/selectTextBox.h"
#include "../header Files/loginForm.h"
#include "../header Files/registerPage.h"
#include "../header Files/homeEvents.h"
#include "../header Files/timelineEvents.h"
#include "../header Files/viewAllEventsEvents.h"
#include "../header Files/addAnEventMenuEvents.h"

void selectTextBox(sf::Event& userEvent, SELECTED_TEXT_BOX& textBoxFlag)
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
                textBoxProperties::enteredTextForTitleBox.pop_back();
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
                textBoxProperties::enteredTextForDateBox.pop_back();
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
                textBoxProperties::enteredTextForDescriptionBox.pop_back();
                textBoxProperties::descriptionBox.setString(textBoxProperties::enteredTextForDescriptionBox);
            }
        }
        else if (userEvent.text.unicode < 128 && textBoxFlag.username == true)
        {
            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
            {
                textBoxProperties::enteredTextForUsernameBox += static_cast<char>(userEvent.text.unicode);
                textBoxProperties::username.setString(textBoxProperties::enteredTextForUsernameBox);
            }
            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForUsernameBox.size() > 0)
            {
                textBoxProperties::enteredTextForUsernameBox.pop_back();
                textBoxProperties::username.setString(textBoxProperties::enteredTextForUsernameBox);
            }
        }
        else if (userEvent.text.unicode < 128 && textBoxFlag.password == true)
        {
            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
            {
                textBoxProperties::enteredTextForPasswordBox += static_cast<char>(userEvent.text.unicode);
                textBoxProperties::password.setString(textBoxProperties::enteredTextForPasswordBox);
            }
            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForPasswordBox.size() > 0)
            {
                textBoxProperties::enteredTextForPasswordBox.pop_back();
                textBoxProperties::password.setString(textBoxProperties::enteredTextForPasswordBox);
            }
        }
        else if (userEvent.text.unicode < 128 && textBoxFlag.search == true)
        {
            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
            {
                textBoxProperties::enteredTextForSearchBox += static_cast<char>(userEvent.text.unicode);
                textBoxProperties::search.setString(textBoxProperties::enteredTextForSearchBox);
            }
            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForSearchBox.size() > 0)
            {
                textBoxProperties::enteredTextForSearchBox.pop_back();
                textBoxProperties::search.setString(textBoxProperties::enteredTextForSearchBox);
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
    std::fstream userInfo;
    std::fstream eventInfo;
    size_t setCounter = 0, posY = 170;
    sf::Text item1;
    sf::Text item2;
    sf::Text item3;

    sf::RenderWindow window(sf::VideoMode(800, 900), "Historya", sf::Style::Close);
    window.setFramerateLimit(30);

    sf::Texture* currentPageTexture = new sf::Texture;
    currentPageTexture->loadFromFile("Images and fonts/Login-form.png");

    sf::Sprite* currentPageSprite = new sf::Sprite;
    currentPageSprite->setTexture(*currentPageTexture);

    sf::Font font;
    font.loadFromFile("images and fonts/alkesregular.ttf");


    textBoxProperties::titleBox.setFont(font);
    textBoxProperties::dateBox.setFont(font);
    textBoxProperties::descriptionBox.setFont(font);
    textBoxProperties::username.setFont(font);
    textBoxProperties::password.setFont(font);
    textBoxProperties::search.setFont(font);

    textBoxProperties::titleBox.setCharacterSize(30);
    textBoxProperties::dateBox.setCharacterSize(30);
    textBoxProperties::descriptionBox.setCharacterSize(30);
    textBoxProperties::username.setCharacterSize(30);
    textBoxProperties::password.setCharacterSize(30);
    textBoxProperties::search.setCharacterSize(30);

    textBoxProperties::titleBox.setFillColor(sf::Color::Black);
    textBoxProperties::dateBox.setFillColor(sf::Color::Black);
    textBoxProperties::descriptionBox.setFillColor(sf::Color::Black);
    textBoxProperties::username.setFillColor(sf::Color::Black);
    textBoxProperties::password.setFillColor(sf::Color::Black);
    textBoxProperties::search.setFillColor(sf::Color::White);

    while (window.isOpen())
    {
        sf::Event userEvent;
        while (window.pollEvent(userEvent))
        {
            loginEvents(userEvent, pageFlag, textBoxFlag, *currentPageTexture, userInfo, textBoxProperties::enteredTextForUsernameBox,
                textBoxProperties::enteredTextForPasswordBox, textBoxProperties::username, textBoxProperties::password);
            homeEvents(userEvent, pageFlag, *currentPageTexture);
            timelineEvents(userEvent, pageFlag, textBoxFlag, *currentPageTexture, eventInfo, head, textBoxProperties::events,
                textBoxProperties::eventTitle);
            viewAllEventsEvents(userEvent, pageFlag, textBoxFlag, *currentPageTexture, textBoxProperties::enteredTextForSearchBox,
                textBoxProperties::search, head, textBoxProperties::eventsAfterSearch);
            addAnEventMenuEvents(userEvent, pageFlag, textBoxFlag, *currentPageTexture, head, eventInfo, textBoxProperties::titleBox,
                textBoxProperties::dateBox, textBoxProperties::descriptionBox, textBoxProperties::enteredTextForTitleBox,
                textBoxProperties::enteredTextForDateBox, textBoxProperties::enteredTextForDescriptionBox);
            registerEvents(userEvent, pageFlag, textBoxFlag, *currentPageTexture, userInfo, 
                textBoxProperties::enteredTextForUsernameBox, textBoxProperties::enteredTextForPasswordBox, textBoxProperties::username,
                textBoxProperties::password);
            selectTextBox(userEvent, textBoxFlag);
        }


        window.clear();



        window.draw(*currentPageSprite);
        window.draw(textBoxProperties::titleBox);
        window.draw(textBoxProperties::dateBox);
        window.draw(textBoxProperties::descriptionBox);
        window.draw(textBoxProperties::username);
        window.draw(textBoxProperties::password);
        window.draw(textBoxProperties::search);

        if (pageFlag.viewAllEvents == true && textBoxProperties::eventsAfterSearch.size() == 0)
        {
            for (size_t i = setCounter + 1; i < setCounter + 4; i++)
            {
                textBoxProperties::events[i].setFont(font);
                textBoxProperties::events[i].setCharacterSize(30);
                textBoxProperties::events[i].setFillColor(sf::Color::White);
                textBoxProperties::events[i].setPosition(115, posY * (i + 1));
            }

            item1 = textBoxProperties::events[setCounter + 1];
            item2 = textBoxProperties::events[setCounter + 2];
            item3 = textBoxProperties::events[setCounter + 3];

            window.draw(item1);
            window.draw(item2);
            window.draw(item3);
        }

        if(pageFlag.viewAllEvents == true && textBoxProperties::eventsAfterSearch.size() != 0)
        {
            for (size_t i = setCounter; i < 1; i++)
            {
                textBoxProperties::eventsAfterSearch[i].setFont(font);
                textBoxProperties::eventsAfterSearch[i].setCharacterSize(30);
                textBoxProperties::eventsAfterSearch[i].setFillColor(sf::Color::White);
                textBoxProperties::eventsAfterSearch[i].setPosition(115, posY * (i + 2));
            }

            item1 = textBoxProperties::eventsAfterSearch[setCounter];

            window.draw(item1);
        }

        window.display();
    }

    delete currentPageTexture;
    delete currentPageSprite;
}