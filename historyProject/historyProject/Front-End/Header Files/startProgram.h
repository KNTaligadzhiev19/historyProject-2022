#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../Back-End/Header Files/timelineMode.h"

struct CURRENT_PAGE
{
    bool loginPage = true;
    bool registerPage = false;
    bool homeMenu = false;
    bool timelineMenu = false;
    bool addAnEventMenu = false;
};

struct SELECTED_TEXT_BOX
{
    bool titleTextBox = false;
    bool dateTextBox = false;
    bool descriptionTextBox = false;
    bool username = false;
    bool password = false;
};

namespace textBoxProperties
{
    static sf::Text titleBox;
    static sf::Text dateBox;
    static sf::Text descriptionBox;
    static sf::Text username;
    static sf::Text password;

    static std::string enteredTextForTitleBox = "";
    static std::string enteredTextForDateBox = "";
    static std::string enteredTextForDescriptionBox = "";
    static std::string enteredTextForUsernameBox = "";
    static std::string enteredTextForPasswordBox = "";
}

void startProgram(NODE* head);