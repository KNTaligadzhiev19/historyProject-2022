#include "../header Files/startProgram.h"
#include "../../Back-End/header Files/registerForm.h"

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

            textBoxProperties::enteredTextForUsernameBox = "";
            textBoxProperties::enteredTextForPasswordBox = "";
            textBoxProperties::username.setString(textBoxProperties::enteredTextForUsernameBox);
            textBoxProperties::password.setString(textBoxProperties::enteredTextForPasswordBox);
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

            textBoxProperties::enteredTextForUsernameBox = "";
            textBoxProperties::enteredTextForPasswordBox = "";
            textBoxProperties::username.setString(textBoxProperties::enteredTextForUsernameBox);
            textBoxProperties::password.setString(textBoxProperties::enteredTextForPasswordBox);
        }
        else if ((userEvent.mouseButton.x >= 75 && userEvent.mouseButton.x <= 230) &&
            (userEvent.mouseButton.y >= 600 && userEvent.mouseButton.y <= 670) && pageFlag.registerPage == true)
        {
            std::cout << "Register user\n";
            registerUser(textBoxProperties::enteredTextForUsernameBox, textBoxProperties::enteredTextForPasswordBox);
            currentPageTexture.loadFromFile("Images and fonts/Login-form.png");
            pageFlag.loginPage = true;
            pageFlag.registerPage = false;
            pageFlag.homeMenu = false;
            pageFlag.timelineMenu = false;
            pageFlag.addAnEventMenu = false;

            textBoxProperties::enteredTextForUsernameBox = "";
            textBoxProperties::enteredTextForPasswordBox = "";
            textBoxProperties::username.setString(textBoxProperties::enteredTextForUsernameBox);
            textBoxProperties::password.setString(textBoxProperties::enteredTextForPasswordBox);
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
        }
        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 120 && userEvent.mouseButton.x <= 690) &&
            (userEvent.mouseButton.y >= 250 && userEvent.mouseButton.y <= 300))
        {
            textBoxFlag.titleTextBox = true;
            textBoxFlag.dateTextBox = false;
            textBoxFlag.descriptionTextBox = false;
            textBoxFlag.username = false;
            textBoxFlag.password = false;
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
            textBoxProperties::password.setPosition(140, 525);
        }
        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 120 && userEvent.mouseButton.x <= 800) &&
            (userEvent.mouseButton.y >= 760 && userEvent.mouseButton.y <= 815))
        {
            setDataToNodes(*head, textBoxProperties::enteredTextForTitleBox, textBoxProperties::enteredTextForDateBox,
                textBoxProperties::enteredTextForDescriptionBox);

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
        else if (userEvent.text.unicode < 128 && textBoxFlag.username == true)
        {
            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
            {
                textBoxProperties::enteredTextForUsernameBox += static_cast<char>(userEvent.text.unicode);
                textBoxProperties::username.setString(textBoxProperties::enteredTextForUsernameBox);
            }
            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForUsernameBox.size() > 0)
            {
                textBoxProperties::enteredTextForUsernameBox = deleteCharFromText(textBoxProperties::enteredTextForUsernameBox);
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
                textBoxProperties::enteredTextForPasswordBox = deleteCharFromText(textBoxProperties::enteredTextForPasswordBox);
                textBoxProperties::password.setString(textBoxProperties::enteredTextForPasswordBox);
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

    textBoxProperties::titleBox.setCharacterSize(30);
    textBoxProperties::dateBox.setCharacterSize(30);
    textBoxProperties::descriptionBox.setCharacterSize(30);
    textBoxProperties::username.setCharacterSize(30);
    textBoxProperties::password.setCharacterSize(30);

    textBoxProperties::titleBox.setFillColor(sf::Color::Black);
    textBoxProperties::dateBox.setFillColor(sf::Color::Black);
    textBoxProperties::descriptionBox.setFillColor(sf::Color::Black);
    textBoxProperties::username.setFillColor(sf::Color::Black);
    textBoxProperties::password.setFillColor(sf::Color::Black);

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
        window.draw(textBoxProperties::username);
        window.draw(textBoxProperties::password);

        window.display();
    }

    delete currentPageTexture;
    delete currentPageSprite;
}