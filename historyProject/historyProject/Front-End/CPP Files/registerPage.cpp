#include "../Header Files/registerPage.h"

void registerEvents(sf::Event& userEvent, CURRENT_PAGE& pageFlag, SELECTED_TEXT_BOX& textBoxFlag, 
    sf::Texture& currentPageTexture, std::fstream& userInfo, std::string& username, std::string& password,
    sf::Text& usernameBar, sf::Text& passwordBar)
{
    switch (userEvent.type)
    {
    case sf::Event::MouseButtonPressed:
    {
        if ((userEvent.mouseButton.x >= 360 && userEvent.mouseButton.x <= 480) &&
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

            username = "";
            password = "";

            usernameBar.setString(username);
            passwordBar.setString(password);

            break;
        }

        else if ((userEvent.mouseButton.x >= 75 && userEvent.mouseButton.x <= 230) &&
            (userEvent.mouseButton.y >= 600 && userEvent.mouseButton.y <= 670) && pageFlag.registerPage == true)
        {
            std::cout << "Register user\n";

            registerUser(username, password, userInfo);

            currentPageTexture.loadFromFile("Images and fonts/Login-form.png");

            pageFlag.loginPage = true;
            pageFlag.registerPage = false;
            pageFlag.homeMenu = false;
            pageFlag.timelineMenu = false;
            pageFlag.addAnEventMenu = false;
            pageFlag.viewAllEvents = false;

            username = "";
            password = "";

            usernameBar.setString(username);
            passwordBar.setString(password);

            break;
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

            usernameBar.setPosition(140, 390);
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

            passwordBar.setPosition(140, 525);
        }
    }
    }
}