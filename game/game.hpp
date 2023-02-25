#pragma once

#include<SFML/Graphics.hpp>
#include"snake.hpp"

class Game{
    public: 
        Game();
        void run();
    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void reder();
        void handlePlayerInput(sf::Keyboard::Key key);
    private:
        static const sf::Time TimePerFrame; 

        sf::RenderWindow mWindow;
        Snake mSnake;
        bool mIsMovingUp, mIsMovingDown, mIsMovingRight, mIsMovingLeft;
};
