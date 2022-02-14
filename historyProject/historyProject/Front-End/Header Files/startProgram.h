#pragma once
#include "../../Back-End/Header Files/timelineMode.h"

struct CURRENT_PAGE
{
    bool homeMenu = true;
    bool timelineMenu = false;
    bool addAnEventMenu = false;
    bool displayAllEvents = false;
};

struct SELECTED_TEXT_BOX
{
    bool titleTextBox = false;
    bool dateDayBox = false;
    bool dateMonthBox = false;
    bool dateYearBox = false;
    bool descriptionTextBox = false;
};

namespace textBoxProperties
{
    static sf::Text titleBox;
    static sf::Text dateDayBox;
    static sf::Text dateMonthBox;
    static sf::Text dateYearBox;
    static sf::Text descriptionBox;

    static std::string enteredTextForTitleBox = "";
    static std::string enteredTextForDayBox = "";
    static std::string enteredTextForMonthBox = "";
    static std::string enteredTextForYearBox = "";
    static std::string enteredTextForDescriptionBox = "";
}

void startProgram(/*NODE* head*/);