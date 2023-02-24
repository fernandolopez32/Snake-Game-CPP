// #include <iostream>
// using namespace std;

// int main(){

//     // sf::RenderWindow windows(sf::VideoMode(800,600), "Snamke Game");
    

//     // sanity check 
//     cout << "hello world again " << endl;
//     return 0;
// }

// #include <SFML/Graphics.hpp>

#include<SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}