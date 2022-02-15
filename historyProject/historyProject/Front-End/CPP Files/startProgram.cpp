#include "../header Files/startProgram.h"
#include "../../Back-End/header Files/registerForm.h"
#include "../../Back-End/header Files/loginForm.h"
#include "../../Back-End/header Files/viewAllEventsPage.h"

void switchPages(sf::RenderWindow& window, sf::Event& userEvent, sf::Texture& currentPageTexture, CURRENT_PAGE& pageFlag,
    SELECTED_TEXT_BOX& textBoxFlag, NODE* head, std::fstream& userInfo, std::fstream& eventInfo)
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
        std::cout << userEvent.mouseButton.x << " ~ " << userEvent.mouseButton.y << std::endl;

        if ((userEvent.mouseButton.x >= 360 && userEvent.mouseButton.x <= 510) &&
            (userEvent.mouseButton.y >= 600 && userEvent.mouseButton.y <= 665) && pageFlag.loginPage == true)
        {
            std::cout << "Enter register form \n";
            currentPageTexture.loadFromFile("Images and fonts/Register-form.png");
            pageFlag.loginPage = false;
            pageFlag.registerPage = true;
            pageFlag.homeMenu = false;
            pageFlag.timelineMenu = false;
            pageFlag.addAnEventMenu = false;
            pageFlag.viewAllEvents = false;

            textBoxProperties::enteredTextForUsernameBox = "";
            textBoxProperties::enteredTextForPasswordBox = "";
            textBoxProperties::username.setString(textBoxProperties::enteredTextForUsernameBox);
            textBoxProperties::password.setString(textBoxProperties::enteredTextForPasswordBox);

            break;
        }
        if ((userEvent.mouseButton.x >= 75 && userEvent.mouseButton.x <= 200) &&
            (userEvent.mouseButton.y >= 600 && userEvent.mouseButton.y <= 665) && pageFlag.loginPage == true)
        {
            if (findUser(textBoxProperties::enteredTextForUsernameBox, textBoxProperties::enteredTextForPasswordBox, userInfo))
            {
                std::cout << "Enter home page \n";
                currentPageTexture.loadFromFile("Images and fonts/Home-page.png");
                pageFlag.loginPage = false;
                pageFlag.registerPage = false;
                pageFlag.homeMenu = true;
                pageFlag.timelineMenu = false;
                pageFlag.addAnEventMenu = false;
                pageFlag.viewAllEvents = false;
            }

            textBoxProperties::enteredTextForUsernameBox = "";
            textBoxProperties::enteredTextForPasswordBox = "";
            textBoxProperties::username.setString(textBoxProperties::enteredTextForUsernameBox);
            textBoxProperties::password.setString(textBoxProperties::enteredTextForPasswordBox);

            break;
        }
        else if ((userEvent.mouseButton.x >= 360 && userEvent.mouseButton.x <= 480) &&
            (userEvent.mouseButton.y >= 600 && userEvent.mouseButton.y <= 665) && pageFlag.registerPage == true)
        {
            std::cout << "Enter login form \n";
            currentPageTexture.loadFromFile("Images and fonts/Login-form.png");
            pageFlag.loginPage = true;
            pageFlag.registerPage = false;
            pageFlag.homeMenu = false;
            pageFlag.timelineMenu = false;
            pageFlag.addAnEventMenu = false;
            pageFlag.viewAllEvents = false;

            textBoxProperties::enteredTextForUsernameBox = "";
            textBoxProperties::enteredTextForPasswordBox = "";
            textBoxProperties::username.setString(textBoxProperties::enteredTextForUsernameBox);
            textBoxProperties::password.setString(textBoxProperties::enteredTextForPasswordBox);

            break;
        }
        else if ((userEvent.mouseButton.x >= 75 && userEvent.mouseButton.x <= 230) &&
            (userEvent.mouseButton.y >= 600 && userEvent.mouseButton.y <= 670) && pageFlag.registerPage == true)
        {
            std::cout << "Register user\n";
            registerUser(textBoxProperties::enteredTextForUsernameBox, textBoxProperties::enteredTextForPasswordBox, userInfo);
            currentPageTexture.loadFromFile("Images and fonts/Login-form.png");
            pageFlag.loginPage = true;
            pageFlag.registerPage = false;
            pageFlag.homeMenu = false;
            pageFlag.timelineMenu = false;
            pageFlag.addAnEventMenu = false;
            pageFlag.viewAllEvents = false;

            textBoxProperties::enteredTextForUsernameBox = "";
            textBoxProperties::enteredTextForPasswordBox = "";
            textBoxProperties::username.setString(textBoxProperties::enteredTextForUsernameBox);
            textBoxProperties::password.setString(textBoxProperties::enteredTextForPasswordBox);

            break;
        }
        else if ((userEvent.mouseButton.x >= 170 && userEvent.mouseButton.x <= 625) &&
            (userEvent.mouseButton.y >= 400 && userEvent.mouseButton.y <= 510) && pageFlag.homeMenu == true)
        {
            std::cout << "Enter timeline menu \n";
            currentPageTexture.loadFromFile("Images and fonts/Timeline-menu.png");
            pageFlag.loginPage = false;
            pageFlag.registerPage = false;
            pageFlag.homeMenu = false;
            pageFlag.timelineMenu = true;
            pageFlag.addAnEventMenu = false;
            pageFlag.viewAllEvents = false;
        }
        else if ((userEvent.mouseButton.x >= 170 && userEvent.mouseButton.x <= 625) &&
            (userEvent.mouseButton.y >= 515 && userEvent.mouseButton.y <= 615) && pageFlag.timelineMenu == true)
        {
            std::cout << "Enter view all events menu \n";
            currentPageTexture.loadFromFile("Images and fonts/View-all-events-page.png");
            pageFlag.loginPage = false;
            pageFlag.registerPage = false;
            pageFlag.homeMenu = false;
            pageFlag.timelineMenu = false;
            pageFlag.viewAllEvents = true;
            pageFlag.addAnEventMenu = false;

            showEvent(eventInfo, head, textBoxProperties::events, textBoxProperties::eventTitle);
        }
        else if ((userEvent.mouseButton.x >= 25 && userEvent.mouseButton.x <= 160) &&
            (userEvent.mouseButton.y >= 815 && userEvent.mouseButton.y <= 870) && pageFlag.viewAllEvents == true)
        {
            std::cout << "Enter timeline menu \n";
            currentPageTexture.loadFromFile("Images and fonts/Timeline-menu.png");
            pageFlag.loginPage = false;
            pageFlag.registerPage = false;
            pageFlag.homeMenu = false;
            pageFlag.timelineMenu = true;
            pageFlag.viewAllEvents = false;
            pageFlag.addAnEventMenu = false;

            textBoxProperties::enteredTextForSearchBox = "";
            textBoxProperties::search.setString(textBoxProperties::enteredTextForSearchBox);
            
        }
        else if ((userEvent.mouseButton.x >= 20 && userEvent.mouseButton.x <= 172) &&
            (userEvent.mouseButton.y >= 800 && userEvent.mouseButton.y <= 880) && pageFlag.timelineMenu == true)
        {
            std::cout << "Back to main menu \n";
            currentPageTexture.loadFromFile("Images and fonts/Home-page.png");
            pageFlag.loginPage = false;
            pageFlag.registerPage = false;
            pageFlag.homeMenu = true;
            pageFlag.timelineMenu = false;
            pageFlag.addAnEventMenu = false;
            pageFlag.viewAllEvents = false;
        }
        else if ((userEvent.mouseButton.x >= 170 && userEvent.mouseButton.x <= 625) &&
            (userEvent.mouseButton.y >= 340 && userEvent.mouseButton.y <= 450) &&
            pageFlag.timelineMenu == true)
        {
            std::cout << "Enter add an event option \n";

            currentPageTexture.loadFromFile("Images and fonts/Add-an-event-form.png");

            pageFlag.loginPage = false;
            pageFlag.registerPage = false;
            pageFlag.addAnEventMenu = true;
            pageFlag.timelineMenu = false;
            pageFlag.homeMenu = false;
            pageFlag.viewAllEvents = false;
        }
        else if (pageFlag.viewAllEvents == true && (userEvent.mouseButton.x >= 150 && userEvent.mouseButton.x <= 570) &&
        (userEvent.mouseButton.y >= 150 && userEvent.mouseButton.y <= 230))
        {
            textBoxFlag.titleTextBox = false;
            textBoxFlag.dateTextBox = false;
            textBoxFlag.descriptionTextBox = false;
            textBoxFlag.username = false;
            textBoxFlag.password = false;
            textBoxFlag.search = true;
            textBoxProperties::search.setPosition(170, 170);

        }
        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 120 && userEvent.mouseButton.x <= 690) &&
            (userEvent.mouseButton.y >= 250 && userEvent.mouseButton.y <= 300))
        {
            textBoxFlag.titleTextBox = true;
            textBoxFlag.dateTextBox = false;
            textBoxFlag.descriptionTextBox = false;
            textBoxFlag.username = false;
            textBoxFlag.password = false;
            textBoxFlag.search = false;
            textBoxProperties::titleBox.setPosition(180, 255);

        }
        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 120 && userEvent.mouseButton.x <= 415) &&
            (userEvent.mouseButton.y >= 390 && userEvent.mouseButton.y <= 450))
        {
            textBoxFlag.titleTextBox = false;
            textBoxFlag.dateTextBox = true;
            textBoxFlag.descriptionTextBox = false;
            textBoxFlag.username = false;
            textBoxFlag.password = false;
            textBoxFlag.search = false;
            textBoxProperties::dateBox.setPosition(180, 400);

        }
        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 120 && userEvent.mouseButton.x <= 690) &&
            (userEvent.mouseButton.y >= 530 && userEvent.mouseButton.y <= 700))
        {
            textBoxFlag.titleTextBox = false;
            textBoxFlag.dateTextBox = false;
            textBoxFlag.descriptionTextBox = true;
            textBoxFlag.username = false;
            textBoxFlag.password = false;
            textBoxFlag.search = false;
            textBoxProperties::descriptionBox.setPosition(140, 540);
        }
        else if (pageFlag.loginPage == true && (userEvent.mouseButton.x >= 75 && userEvent.mouseButton.x <= 720) &&
            (userEvent.mouseButton.y >= 380 && userEvent.mouseButton.y <= 440))
        {
            textBoxFlag.titleTextBox = false;
            textBoxFlag.dateTextBox = false;
            textBoxFlag.descriptionTextBox = false;
            textBoxFlag.username = true;
            textBoxFlag.password = false;
            textBoxFlag.search = false;
            textBoxProperties::username.setPosition(140, 390);
        }
        else if (pageFlag.loginPage == true && (userEvent.mouseButton.x >= 75 && userEvent.mouseButton.x <= 720) &&
            (userEvent.mouseButton.y >= 515 && userEvent.mouseButton.y <= 580))
        {
            textBoxFlag.titleTextBox = false;
            textBoxFlag.dateTextBox = false;
            textBoxFlag.descriptionTextBox = false;
            textBoxFlag.username = false;
            textBoxFlag.password = true;
            textBoxFlag.search = false;
            textBoxProperties::password.setPosition(140, 525);
        }
        else if (pageFlag.registerPage == true && (userEvent.mouseButton.x >= 75 && userEvent.mouseButton.x <= 720) &&
            (userEvent.mouseButton.y >= 380 && userEvent.mouseButton.y <= 440))
        {
            textBoxFlag.titleTextBox = false;
            textBoxFlag.dateTextBox = false;
            textBoxFlag.descriptionTextBox = false;
            textBoxFlag.username = true;
            textBoxFlag.password = false;
            textBoxFlag.search = false;
            textBoxProperties::username.setPosition(140, 390);
        }
        else if (pageFlag.registerPage == true && (userEvent.mouseButton.x >= 75 && userEvent.mouseButton.x <= 720) &&
            (userEvent.mouseButton.y >= 520 && userEvent.mouseButton.y <= 580))
        {
            textBoxFlag.titleTextBox = false;
            textBoxFlag.dateTextBox = false;
            textBoxFlag.descriptionTextBox = false;
            textBoxFlag.username = false;
            textBoxFlag.password = true;
            textBoxFlag.search = false;
            textBoxProperties::password.setPosition(140, 525);
        }
        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 120 && userEvent.mouseButton.x <= 800) &&
            (userEvent.mouseButton.y >= 760 && userEvent.mouseButton.y <= 815))
        {
            setDataToNodes(head, textBoxProperties::enteredTextForTitleBox, textBoxProperties::enteredTextForDateBox,
                textBoxProperties::enteredTextForDescriptionBox, eventInfo);

            textBoxProperties::enteredTextForTitleBox = "";
            textBoxProperties::enteredTextForDateBox = "";
            textBoxProperties::enteredTextForDescriptionBox = "";

            textBoxProperties::titleBox.setString(textBoxProperties::enteredTextForTitleBox);
            textBoxProperties::dateBox.setString(textBoxProperties::enteredTextForDateBox);
            textBoxProperties::descriptionBox.setString(textBoxProperties::enteredTextForDescriptionBox);

            currentPageTexture.loadFromFile("Images and fonts/Timeline-menu.png");

            pageFlag.loginPage = false;
            pageFlag.registerPage = false;
            pageFlag.homeMenu = false;
            pageFlag.addAnEventMenu = false;
            pageFlag.timelineMenu = true;
            pageFlag.viewAllEvents = false;

            break;
        }
        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 225 && userEvent.mouseButton.x <= 340) &&
            (userEvent.mouseButton.y >= 760 && userEvent.mouseButton.y <= 815))
        {
            textBoxProperties::enteredTextForTitleBox = "";
            textBoxProperties::enteredTextForDateBox = "";
            textBoxProperties::enteredTextForDescriptionBox = "";

            textBoxProperties::titleBox.setString(textBoxProperties::enteredTextForTitleBox);
            textBoxProperties::dateBox.setString(textBoxProperties::enteredTextForDateBox);
            textBoxProperties::descriptionBox.setString(textBoxProperties::enteredTextForDescriptionBox);

            currentPageTexture.loadFromFile("Images and fonts/Timeline-menu.png");

            pageFlag.loginPage = false;
            pageFlag.registerPage = false;
            pageFlag.homeMenu = false;
            pageFlag.addAnEventMenu = false;
            pageFlag.timelineMenu = true;
            pageFlag.viewAllEvents = false;

            break;
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
            switchPages(window, userEvent, *currentPageTexture, pageFlag, textBoxFlag, head, userInfo, eventInfo);
            selectTextBox(window, userEvent, textBoxFlag);
        }


        window.clear();



        window.draw(*currentPageSprite);
        window.draw(textBoxProperties::titleBox);
        window.draw(textBoxProperties::dateBox);
        window.draw(textBoxProperties::descriptionBox);
        window.draw(textBoxProperties::username);
        window.draw(textBoxProperties::password);
        window.draw(textBoxProperties::search);

        if (pageFlag.viewAllEvents)
        {
            for (size_t i = setCounter + 1; i < setCounter + 5; i++)
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

        window.display();
    }

    delete currentPageTexture;
    delete currentPageSprite;
}