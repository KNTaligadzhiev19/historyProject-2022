#include <SFML/Graphics.hpp>

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
            if (userEvent.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        window.draw(*currentPageSprite);

        window.display();
    }

    delete currentPageTexture;
    delete currentPageSprite;
}