#include "../Header Files/homeEvents.h"

void homeEvents(sf::Event userEvent, CURRENT_PAGE& pageFlag, sf::Texture& currentPageTexture)
{
    switch (userEvent.type)
    {
    case sf::Event::MouseButtonPressed:
    {
        if ((userEvent.mouseButton.x >= 170 && userEvent.mouseButton.x <= 625) &&
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
    }
    }
}