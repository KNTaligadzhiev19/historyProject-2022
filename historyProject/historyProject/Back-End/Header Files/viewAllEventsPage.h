#pragma once
#include "timelineMode.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>

void showEvent(std::fstream& userInfo, NODE*& head, std::vector<sf::Text>& events, std::vector<std::string>& eventTitles);