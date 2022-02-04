#pragma once

struct CURRENT_PAGE
{
    bool homeMenu = true;
    bool timelineMenu = false;
    bool addAnEventMenu = false;
};

struct SELECTED_TEXT_BOX
{
    bool titleTextBox = false;
    bool dateTextBox = false;
    bool descriptionTextBox = false;
};

namespace textBoxProperties
{
    static sf::Text titleBox;
    static sf::Text dateBox;
    static sf::Text descriptionBox;

    static std::string enteredTextForTitleBox = "";
    static std::string enteredTextForDateBox = "";
    static std::string enteredTextForDescriptionBox = "";
}

void startProgram();