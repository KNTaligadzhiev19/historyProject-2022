#include "../Header Files/timelineEvents.h"

void timelineEvents(sf::Event userEvent, CURRENT_PAGE& pageFlag, SELECTED_TEXT_BOX& textBoxFlag, 
    sf::Texture& currentPageTexture, std::fstream& eventInfo, NODE* head, std::vector<sf::Text>& events, std::vector<std::string>& eventTitle)
{
    switch (userEvent.type)
    {
    case sf::Event::MouseButtonPressed:
    {
        if ((userEvent.mouseButton.x >= 170 && userEvent.mouseButton.x <= 625) &&
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

            showEvent(eventInfo, head, events, eventTitle);
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
            (userEvent.mouseButton.y >= 340 && userEvent.mouseButton.y <= 450) && pageFlag.timelineMenu == true)
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
    }
    }
}