#include "game.hpp"

const sf:: Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game:: Game()
:mWindow(sf::VideoMode(800, 600),"Snake Game")
,mSnake()
,mIsmovingUp(false)
,mIsmovingDown(false)
,mIsmovingRight(false)
,mIsmovingLeft(false)
{
    mWindow.setKeyRepeatEnabled(false);
}
void Game::processEvents()
{
    sf:: Event event;
    while (mWindow.pollEvent(evetn))
    {
        switch(event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code);
                break;

            case sf::Event::Closed:
                mWindow.close();
                break;
            default:
                break;
        }
    }
    
}