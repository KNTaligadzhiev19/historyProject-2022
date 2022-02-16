#include "../Header Files/viewAllEventsEvents.h"

void viewAllEventsEvents(sf::Event userEvent, CURRENT_PAGE& pageFlag, SELECTED_TEXT_BOX& textBoxFlag, sf::Texture& currentPageTexture,
    std::string& search, sf::Text& serachBar, NODE*& head, std::vector<sf::Text>& eventsAfterSearch)
{
    switch (userEvent.type)
    {
    case sf::Event::MouseButtonPressed:
    {
        if ((userEvent.mouseButton.x >= 25 && userEvent.mouseButton.x <= 160) &&
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

            search = "";
            serachBar.setString(search);
        }

        if ((userEvent.mouseButton.x >= 590 && userEvent.mouseButton.x <= 680) &&
            (userEvent.mouseButton.y >= 140 && userEvent.mouseButton.y <= 220) && pageFlag.viewAllEvents == true)
        {
            std::cout << "Start searching \n";

            searchForEvent(head, search, eventsAfterSearch);
        }

        else if ((userEvent.mouseButton.x >= 170 && userEvent.mouseButton.x <= 625) &&
        (userEvent.mouseButton.y >= 340 && userEvent.mouseButton.y <= 450) && pageFlag.viewAllEvents == true)
        {
            std::cout << "Enter edit option \n";

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

            serachBar.setPosition(170, 170);
        }
    }
    }
}