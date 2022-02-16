#pragma once
#include "../../Back-End/Header Files/timelineMode.h"
#include "../../Back-End/header Files/registerForm.h"
#include "../../Back-End/header Files/loginForm.h"
#include "../../Back-End/header Files/viewAllEventsPage.h"
#include "../../Back-End/header Files/eventOptions.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

struct CURRENT_PAGE
{
    bool loginPage = true;
    bool registerPage = false;
    bool homeMenu = false;
    bool timelineMenu = false;
    bool viewAllEvents = false;
    bool addAnEventMenu = false;
};

struct SELECTED_TEXT_BOX
{
    bool titleTextBox = false;
    bool dateTextBox = false;
    bool descriptionTextBox = false;
    bool username = false;
    bool password = false;
    bool search = false;
};

namespace textBoxProperties
{
    static sf::Text titleBox;
    static sf::Text dateBox;
    static sf::Text descriptionBox;
    static sf::Text username;
    static sf::Text password;
    static sf::Text search;
    static std::vector<sf::Text> events;
    static std::vector<sf::Text> eventsAfterSearch;
    //bool searchFlag = false;

    static std::string enteredTextForTitleBox = "";
    static std::string enteredTextForDateBox = "";
    static std::string enteredTextForDescriptionBox = "";
    static std::string enteredTextForUsernameBox = "";
    static std::string enteredTextForPasswordBox = "";
    static std::string enteredTextForSearchBox = "";
    static std::vector<std::string> eventTitle;
}

void startProgram(NODE* head);