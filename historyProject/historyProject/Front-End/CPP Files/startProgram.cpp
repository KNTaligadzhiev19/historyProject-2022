#include <SFML/Graphics.hpp>
#include <iostream>

void switchPages(sf::RenderWindow& window, sf::Event& userEvent, sf::Texture& currentPageTexture)
{
    switch (userEvent.type)
    {
    case sf::Event::Closed:
    {
        window.close();
        break;
    }

    case sf::Event::MouseButtonPressed:
    {
        if ((userEvent.mouseButton.x >= 170 && userEvent.mouseButton.x <= 625) &&
            (userEvent.mouseButton.y >= 400 && userEvent.mouseButton.y <= 510))
        {
            std::cout << "Enter timeline menu \n";
            currentPageTexture.loadFromFile("Images and fonts/Timeline menu.png");
        }

        else if ((userEvent.mouseButton.x >= 20 && userEvent.mouseButton.x <= 172) &&
            (userEvent.mouseButton.y >= 800 && userEvent.mouseButton.y <= 880))
        {
            std::cout << "Back to main menu \n";
            currentPageTexture.loadFromFile("Images and fonts/Home-page.png");
        }

        break;
    }

    default:
        break;
    }
}

void startProgram()
{
    sf::RenderWindow window(sf::VideoMode(800, 900), "Historya", sf::Style::Close);
    window.setFramerateLimit(30);

    sf::Texture* currentPageTexture = new sf::Texture;
    currentPageTexture->loadFromFile("Images and fonts/Home-page.png");

    sf::Sprite* currentPageSprite = new sf::Sprite;
    currentPageSprite->setTexture(*currentPageTexture);

    while (window.isOpen())
    {
        sf::Event userEvent;
        while (window.pollEvent(userEvent))
        {
            switchPages(window, userEvent, *currentPageTexture);
        }

        window.clear();

        window.draw(*currentPageSprite);

        window.display();
    }

    delete currentPageTexture;
    delete currentPageSprite;
}