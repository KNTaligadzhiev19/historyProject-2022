#include <SFML/Graphics.hpp>
#include <iostream>

void getCursorPosition(sf::RenderWindow& window)
{
    int mPosX = 0;
    int mPosY = 0;

    mPosX = sf::Mouse::getPosition(window).x;
    mPosY = sf::Mouse::getPosition(window).y;
    std::cout << mPosX << " ~ " << mPosY << "\n";
}