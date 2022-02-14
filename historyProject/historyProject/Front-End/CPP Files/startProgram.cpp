#include "../Header Files/loginForm.h"
#include <iostream>
//#include "../header Files/startProgram.h"
//#include "../../Back-End/header Files/timelineMode.h"

//void switchPages(sf::RenderWindow& window, sf::Event& userEvent, sf::Texture& currentPageTexture, CURRENT_PAGE& pageFlag,
//    SELECTED_TEXT_BOX& textBoxFlag, NODE* head)
//{
//    switch (userEvent.type)
//    {
//    case sf::Event::Closed:
//    {
//        window.close();
//        break;
//    }
//
//    case sf::Event::MouseButtonPressed:
//    {
//        if ((userEvent.mouseButton.x >= 170 && userEvent.mouseButton.x <= 625) &&
//            (userEvent.mouseButton.y >= 400 && userEvent.mouseButton.y <= 510) && pageFlag.homeMenu == true)
//        {
//            std::cout << "Enter timeline menu \n";
//            currentPageTexture.loadFromFile("Images and fonts/Timeline menu.png");
//            pageFlag.homeMenu = false;
//            pageFlag.timelineMenu = true;
//            pageFlag.addAnEventMenu = false;
//            pageFlag.displayAllEvents = false;
//        }
//        else if ((userEvent.mouseButton.x >= 20 && userEvent.mouseButton.x <= 172) &&
//            (userEvent.mouseButton.y >= 800 && userEvent.mouseButton.y <= 880) && pageFlag.timelineMenu == true)
//        {
//            std::cout << "Back to main menu \n";
//            currentPageTexture.loadFromFile("Images and fonts/Home-page.png");
//            pageFlag.homeMenu = true;
//            pageFlag.timelineMenu = false;
//            pageFlag.addAnEventMenu = false;
//            pageFlag.displayAllEvents = false;
//        }
//        else if ((userEvent.mouseButton.x >= 170 && userEvent.mouseButton.x <= 625) &&
//            (userEvent.mouseButton.y >= 340 && userEvent.mouseButton.y <= 450) &&
//            pageFlag.timelineMenu == true)
//        {
//            std::cout << "Enter add an event option \n";
//
//            currentPageTexture.loadFromFile("Images and fonts/Add an event form.png");
//
//            pageFlag.addAnEventMenu = true;
//            pageFlag.timelineMenu = false;
//            pageFlag.homeMenu = false;
//            pageFlag.displayAllEvents = false;
//        }
//        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 95 && userEvent.mouseButton.x <= 700) &&
//            (userEvent.mouseButton.y >= 235 && userEvent.mouseButton.y <= 300))
//        {
//            textBoxFlag.titleTextBox = true;
//            textBoxFlag.dateDayBox = false;
//            textBoxFlag.dateMonthBox = false;
//            textBoxFlag.dateYearBox = false;
//            textBoxFlag.descriptionTextBox = false;
//            textBoxProperties::titleBox.setPosition(145, 245);
//        }
//        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 95 && userEvent.mouseButton.x <= 250) &&
//            (userEvent.mouseButton.y >= 385 && userEvent.mouseButton.y <= 445))
//        {
//            textBoxFlag.titleTextBox = false;
//            textBoxFlag.dateDayBox = true;
//            textBoxFlag.dateMonthBox = false;
//            textBoxFlag.dateYearBox = false;
//            textBoxFlag.descriptionTextBox = false;
//            textBoxProperties::dateDayBox.setPosition(150, 395);
//        }
//        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 280 && userEvent.mouseButton.x <= 345) &&
//            (userEvent.mouseButton.y >= 385 && userEvent.mouseButton.y <= 445))
//        {
//            textBoxFlag.titleTextBox = false;
//            textBoxFlag.dateDayBox = false;
//            textBoxFlag.dateMonthBox = true;
//            textBoxFlag.dateYearBox = false;
//            textBoxFlag.descriptionTextBox = false;
//            textBoxProperties::dateMonthBox.setPosition(330, 395);
//        }
//        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 480 && userEvent.mouseButton.x <= 665) &&
//            (userEvent.mouseButton.y >= 385 && userEvent.mouseButton.y <= 445))
//        {
//            textBoxFlag.titleTextBox = false;
//            textBoxFlag.dateDayBox = false;
//            textBoxFlag.dateMonthBox = false;
//            textBoxFlag.dateYearBox = true;
//            textBoxFlag.descriptionTextBox = false;
//            textBoxProperties::dateYearBox.setPosition(540, 395);
//        }
//        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 480 && userEvent.mouseButton.x <= 665) &&
//            (userEvent.mouseButton.y >= 385 && userEvent.mouseButton.y <= 445))
//        {
//            textBoxFlag.titleTextBox = false;
//            textBoxFlag.dateDayBox = false;
//            textBoxFlag.dateMonthBox = false;
//            textBoxFlag.dateYearBox = true;
//            textBoxFlag.descriptionTextBox = true;
//            textBoxProperties::descriptionBox.setPosition(530, 395);
//        }
//        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 92 && userEvent.mouseButton.x <= 190) &&
//            (userEvent.mouseButton.y >= 775 && userEvent.mouseButton.y <= 835))
//        {
//            std::string date = textBoxProperties::enteredTextForDayBox + "." + textBoxProperties::enteredTextForMonthBox + "." + textBoxProperties::enteredTextForYearBox;
//            setDataToNodes(*head, textBoxProperties::enteredTextForTitleBox, date,
//                textBoxProperties::enteredTextForDescriptionBox);
//
//            textBoxProperties::enteredTextForTitleBox = "";
//            textBoxProperties::enteredTextForDayBox = "";
//            textBoxProperties::enteredTextForMonthBox = "";
//            textBoxProperties::enteredTextForYearBox = "";
//            textBoxProperties::enteredTextForDescriptionBox = "";
//
//            textBoxProperties::titleBox.setString(textBoxProperties::enteredTextForTitleBox);
//            textBoxProperties::dateDayBox.setString(textBoxProperties::enteredTextForDayBox);
//            textBoxProperties::descriptionBox.setString(textBoxProperties::enteredTextForDescriptionBox);
//
//            currentPageTexture.loadFromFile("Images and fonts/Timeline menu.png");
//
//            pageFlag.homeMenu = false;
//            pageFlag.addAnEventMenu = false;
//            pageFlag.timelineMenu = true;
//            pageFlag.displayAllEvents = false;
//        }
//        else if (pageFlag.addAnEventMenu == true && (userEvent.mouseButton.x >= 200 && userEvent.mouseButton.x <= 330) &&
//            (userEvent.mouseButton.y >= 775 && userEvent.mouseButton.y <= 835))
//        {
//            textBoxProperties::enteredTextForTitleBox = "";
//            textBoxProperties::enteredTextForDayBox = "";
//            textBoxProperties::enteredTextForDescriptionBox = "";
//
//            textBoxProperties::titleBox.setString(textBoxProperties::enteredTextForTitleBox);
//            textBoxProperties::dateDayBox.setString(textBoxProperties::enteredTextForDayBox);
//            textBoxProperties::descriptionBox.setString(textBoxProperties::enteredTextForDescriptionBox);
//
//            currentPageTexture.loadFromFile("Images and fonts/Timeline menu.png");
//
//            pageFlag.homeMenu = false;
//            pageFlag.addAnEventMenu = false;
//            pageFlag.timelineMenu = true;
//            pageFlag.displayAllEvents = false;
//        }
//        else if ((userEvent.mouseButton.x >= 180 && userEvent.mouseButton.x <= 620) &&
//            (userEvent.mouseButton.y >= 515 && userEvent.mouseButton.y <= 620) &&
//            pageFlag.timelineMenu == true)
//        {
//            std::cout << "Enter view all events menu \n";
//
//            currentPageTexture.loadFromFile("");
//
//            pageFlag.addAnEventMenu = false;
//            pageFlag.timelineMenu = false;
//            pageFlag.homeMenu = false;
//            pageFlag.displayAllEvents = true;
//        }
//        break;
//    }
//
//    default:
//        break;
//    }
//}
//
//std::string deleteCharFromText(std::string enteredText)
//{
//    std::string processedText;
//
//    for (size_t i = 0; i < enteredText.size() - 1; i++)
//    {
//        processedText += enteredText[i];
//    }
//
//    return processedText;
//}
//
//void selectTextBox(sf::RenderWindow& window, sf::Event& userEvent, SELECTED_TEXT_BOX& textBoxFlag)
//{
//    switch (userEvent.type)
//    {
//    case sf::Event::TextEntered:
//        if (userEvent.text.unicode < 128 && textBoxFlag.titleTextBox == true)
//        {
//            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
//            {
//                textBoxProperties::enteredTextForTitleBox += static_cast<char>(userEvent.text.unicode);
//                textBoxProperties::titleBox.setString(textBoxProperties::enteredTextForTitleBox);
//            }
//            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForTitleBox.size() > 0)
//            {
//                textBoxProperties::enteredTextForTitleBox = deleteCharFromText(textBoxProperties::enteredTextForTitleBox);
//                textBoxProperties::titleBox.setString(textBoxProperties::enteredTextForTitleBox);
//            }
//        }
//        else if (userEvent.text.unicode < 128 && textBoxFlag.dateDayBox == true)
//        {
//            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
//            {
//                textBoxProperties::enteredTextForDayBox += static_cast<char>(userEvent.text.unicode);
//                textBoxProperties::dateDayBox.setString(textBoxProperties::enteredTextForDayBox);
//            }
//            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForDayBox.size() > 0)
//            {
//                textBoxProperties::enteredTextForDayBox = deleteCharFromText(textBoxProperties::enteredTextForDayBox);
//                textBoxProperties::dateDayBox.setString(textBoxProperties::enteredTextForDayBox);
//            }
//        }
//        else if (userEvent.text.unicode < 128 && textBoxFlag.dateMonthBox == true)
//        {
//            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
//            {
//                textBoxProperties::enteredTextForMonthBox += static_cast<char>(userEvent.text.unicode);
//                textBoxProperties::dateMonthBox.setString(textBoxProperties::enteredTextForMonthBox);
//            }
//            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForMonthBox.size() > 0)
//            {
//                textBoxProperties::enteredTextForMonthBox = deleteCharFromText(textBoxProperties::enteredTextForMonthBox);
//                textBoxProperties::dateMonthBox.setString(textBoxProperties::enteredTextForMonthBox);
//            }
//        }
//        else if (userEvent.text.unicode < 128 && textBoxFlag.dateYearBox == true)
//        {
//            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
//            {
//                textBoxProperties::enteredTextForYearBox += static_cast<char>(userEvent.text.unicode);
//                textBoxProperties::dateYearBox.setString(textBoxProperties::enteredTextForYearBox);
//            }
//            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForYearBox.size() > 0)
//            {
//                textBoxProperties::enteredTextForYearBox = deleteCharFromText(textBoxProperties::enteredTextForYearBox);
//                textBoxProperties::dateYearBox.setString(textBoxProperties::enteredTextForYearBox);
//            }
//        }
//        else if (userEvent.text.unicode < 128 && textBoxFlag.descriptionTextBox == true)
//        {
//            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
//            {
//                textBoxProperties::enteredTextForDescriptionBox += static_cast<char>(userEvent.text.unicode);
//                textBoxProperties::descriptionBox.setString(textBoxProperties::enteredTextForDescriptionBox);
//            }
//            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForDescriptionBox.size() > 0)
//            {
//                textBoxProperties::enteredTextForDescriptionBox = deleteCharFromText(textBoxProperties::enteredTextForDescriptionBox);
//                textBoxProperties::descriptionBox.setString(textBoxProperties::enteredTextForDescriptionBox);
//            }
//        }
//
//        break;
//    default:
//        break;
//    }
//}

void createPages(std::vector<PagePropertiesContainer*>& pages)
{
    pages.push_back(createLoginPage());
}

void initPages(std::vector<PagePropertiesContainer*>& pages)
{
    for (auto page : pages)
    {
        page->initialize();
    }
}

void destroyPages(std::vector<PagePropertiesContainer*>& pages)
{
    for (auto page : pages)
    {
        page->destroy();
    }
}

PagePropertiesContainer* getPage(PagePropertiesContainer* cs = createLoginPage())
{
    return cs;
}

void startProgram(/*NODE* head*/)
{
    bool shouldRun = true;
    PagePropertiesContainer* currentPage = nullptr;
    std::vector<PagePropertiesContainer*> pages;

    sf::RenderWindow window(sf::VideoMode(800, 900), "Historya", sf::Style::Close);
    window.setFramerateLimit(30);
    std::string selectedField = "";
    /*CURRENT_PAGE pageFlag;
    SELECTED_TEXT_BOX textBoxFlag;


    sf::Texture* currentPageTexture = new sf::Texture;
    currentPageTexture->loadFromFile("Images and fonts/Home-page.png");

    sf::Sprite* currentPageSprite = new sf::Sprite;
    currentPageSprite->setTexture(*currentPageTexture);

    sf::Font font;
    font.loadFromFile("images and fonts/alkesregular.ttf");

    textBoxProperties::titleBox.setFont(font);
    textBoxProperties::dateDayBox.setFont(font);
    textBoxProperties::dateMonthBox.setFont(font);
    textBoxProperties::dateYearBox.setFont(font);
    textBoxProperties::descriptionBox.setFont(font);

    textBoxProperties::titleBox.setCharacterSize(30);
    textBoxProperties::dateDayBox.setCharacterSize(30);
    textBoxProperties::dateMonthBox.setCharacterSize(30);
    textBoxProperties::dateYearBox.setCharacterSize(30);
    textBoxProperties::descriptionBox.setCharacterSize(30);

    textBoxProperties::titleBox.setFillColor(sf::Color::Black);
    textBoxProperties::dateDayBox.setFillColor(sf::Color::Black);
    textBoxProperties::dateMonthBox.setFillColor(sf::Color::Black);
    textBoxProperties::dateYearBox.setFillColor(sf::Color::Black);
    textBoxProperties::descriptionBox.setFillColor(sf::Color::Black);*/

    createPages(pages);
    initPages(pages);
    currentPage = pages[0];

    while (window.isOpen())
    {
        sf::Event userEvent;
        while (window.pollEvent(userEvent))
        {
            /*switchPages(window, userEvent, *currentPageTexture, pageFlag, textBoxFlag, head);
            selectTextBox(window, userEvent, textBoxFlag);

            if (userEvent.type == sf::Event::MouseButtonPressed)
            {
                std::cout << userEvent.mouseButton.x << " ~ " << userEvent.mouseButton.y << "\n";
            }*/

            if (userEvent.type == sf::Event::Closed)
            {
                window.close();
            }
            else
            {

                if (!(shouldRun = currentPage->handleEvents(userEvent, selectedField)))
                {
                    window.close();
                    break;
                }
                pages[0]->selectTextBox(userEvent, selectedField);
                //currentPage = getPage();
            }

        }
        if (shouldRun)
        {
            window.clear();
            currentPage->draw(window);
            window.display();
        }

        /*window.clear();

        window.draw(*currentPageSprite);
        window.draw(textBoxProperties::titleBox);
        window.draw(textBoxProperties::dateDayBox);
        window.draw(textBoxProperties::dateMonthBox);
        window.draw(textBoxProperties::dateYearBox);
        window.draw(textBoxProperties::descriptionBox);

        window.display();*/
    }

    //destroyPages(pages);
    /*delete currentPageTexture;
    delete currentPageSprite;*/

    return;
}