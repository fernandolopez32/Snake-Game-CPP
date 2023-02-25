#include <SFML/Graphics.hpp>

int main()
{
    // sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }
 sf::RenderWindow window(sf::VideoMode(800,600),"Snake Game");

 // creating a rectangle shape for the snake
 sf::RectangleShape snake(sf::Vector2f(20,20));
 snake.setFillColor(sf::Color::Green);
 snake.setPosition(400,300);

 while(window.isOpen())
 {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
    window.clear();
    window.draw(snake);
    window.display();
    }


    return 0;
}
