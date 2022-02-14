#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

bool findUser(std::string enteredUsername, std::string enteredPassword, std::fstream& userInfo);