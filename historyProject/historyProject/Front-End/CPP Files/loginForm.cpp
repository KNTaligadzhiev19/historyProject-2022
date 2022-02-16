#include "../Header Files/loginForm.h"

void loginEvents(sf::Event& userEvent, CURRENT_PAGE& pageFlag, SELECTED_TEXT_BOX& textBoxFlag, 
    sf::Texture& currentPageTexture, std::fstream& userInfo, std::string& username, std::string& password, 
    sf::Text& usernameBox, sf::Text& passwordBox)
{
    switch (userEvent.type)
    {
    case sf::Event::MouseButtonPressed:
    {
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

            username = "";
            password = "";

            usernameBox.setString(username);
            passwordBox.setString(password);

            break;
        }

        if ((userEvent.mouseButton.x >= 75 && userEvent.mouseButton.x <= 200) &&
            (userEvent.mouseButton.y >= 600 && userEvent.mouseButton.y <= 665) && pageFlag.loginPage == true)
        {
            if (findUser(username, password, userInfo))
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

            username = "";
            password = "";

            usernameBox.setString(username);
            passwordBox.setString(password);

            break;
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

            usernameBox.setPosition(140, 390);
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

            passwordBox.setPosition(140, 525);
        }
    }
    }
}