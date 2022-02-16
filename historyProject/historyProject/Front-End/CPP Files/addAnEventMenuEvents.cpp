#include "../Header Files/addAnEventMenuEvents.h"

void addAnEventMenuEvents(sf::Event userEvent, CURRENT_PAGE& pageFlag, SELECTED_TEXT_BOX& textBoxFlag, 
sf::Texture& currentPageTexture, NODE* head, std::fstream& eventInfo, sf::Text& title, sf::Text& date, sf::Text& description,
std::string& titleStr, std::string& dateStr, std::string& descriptionStr)
{
    switch (userEvent.type)
    {
    case sf::Event::MouseButtonPressed:
    {
        if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 120 && userEvent.mouseButton.x <= 690) &&
        (userEvent.mouseButton.y >= 250 && userEvent.mouseButton.y <= 300))
        {
            textBoxFlag.titleTextBox = true;
            textBoxFlag.dateTextBox = false;
            textBoxFlag.descriptionTextBox = false;
            textBoxFlag.username = false;
            textBoxFlag.password = false;
            textBoxFlag.search = false;

            title.setPosition(180, 255);

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

            date.setPosition(180, 400);

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

            description.setPosition(140, 540);
        }

        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 120 && userEvent.mouseButton.x <= 800) &&
        (userEvent.mouseButton.y >= 760 && userEvent.mouseButton.y <= 815))
        {
            setDataToNodes(head, titleStr, dateStr, descriptionStr, eventInfo);

            titleStr = "";
            dateStr = "";
            descriptionStr = "";

            title.setString(titleStr);
            date.setString(dateStr);
            description.setString(descriptionStr);

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
            titleStr = "";
            dateStr = "";
            descriptionStr = "";

            title.setString(titleStr);
            date.setString(dateStr);
            description.setString(descriptionStr);

            currentPageTexture.loadFromFile("Images and fonts/Timeline-menu.png");

            pageFlag.loginPage = false;
            pageFlag.registerPage = false;
            pageFlag.homeMenu = false;
            pageFlag.addAnEventMenu = false;
            pageFlag.timelineMenu = true;
            pageFlag.viewAllEvents = false;

            break;
        }
    }
    }
}