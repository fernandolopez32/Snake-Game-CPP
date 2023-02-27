// #include "game.hpp"

// const sf:: Time Game::TimePerFrame = sf::seconds(1.f/60.f);

// Game:: Game()
// :mWindow(sf::VideoMode(800, 600),"Snake Game")
// ,mSnake()
// ,mIsmovingUp(false)
// ,mIsmovingDown(false)
// ,mIsmovingRight(false)
// ,mIsmovingLeft(false)
// {
//     mWindow.setKeyRepeatEnabled(false);
// }

// // game process of events 
// void Game::processEvents()
// {
//     sf:: Event event;
//     while (mWindow.pollEvent(event))
//     {
//         switch(event.type)
//         {
//             case sf::Event::KeyPressed:
//                 handlePlayerInput(event.key.code);
//                 break;

//             case sf::Event::Closed:
//                 mWindow.close();
//                 break;
//             default:
//                 break;
//         }
//     }
    
// }

// // handling player inputs 

// void Game::handlePlayerInput(sf::Keyboard::Key key)
//     {
//     if(key == sf::Keyboard::Up)
//         {            
//             mIsMovingUp = true;
//             mIsMovingDown = false;
//             mIsMovingLeft = false;
//             mIsMovingRight = false;
//         }
//     else if(key == sf::Keyboard::Down)
//         {     
//             mIsMovingUp = false;
//             mIsMovingDown = true;
//             mIsMovingLeft = false;
//             mIsMovingRight = false;       
//         }
//     else if(key == sf::Keyboard::Left)
//         {   
//             mIsMovingUp = false;
//             mIsMovingDown = false;
//             mIsMovingLeft = true;
//             mIsMovingRight = false;  
//         }
//     else if(key == sf::Keyboard::Right)
//         { 
//             mIsMovingUp = false;
//             mIsMovingDown = false;
//             mIsMovingLeft = false;
//             mIsMovingRight = true;           
//         }
//     }

// // game update
// // void Game::update(sf::Time deltaTime)
// // {
// //     const float speed = 100.f;

// //     sf::Vector2f movement(0.f,0.f);
    
// //     if(mIsMovingUp)
// //     {
// //         movement.y -= Snake::Speed;
// //     }
// //     if (mIsMovingDown)
// //     {
// //         movement.y += Snake::Speed;
// //     }
// //     if (mIsMovingLeft)
// //     {
// //         movement.x -= Snake::Speed;
// //     }
// //     if (mIsMovingRight)
// //     {
// //         movement.x += Snake::Speed;
// //     }
// //     mSnake.move(movement * deltaTime.asSeconds());
    
// //     if (mSnake.getPosition().x < 0 || mSnake.getPosition().x > mWindow.getSize().x - mSnake.getSize().x || mSnake.getPosition().y < 0 || mSnake.getPosition().y > mWindow.getSize().y - mSnake.getSize().y)
// //     {
// //         mWindow.close();
// //     }
// // }
// void Game::update(sf::Time deltaTime)
// {
//     const float speed = 100.f;

//     sf::Vector2f movement(0.f, 0.f);

//     if (mIsMovingUp)
//     {
//         movement.y -= speed;
//     }
//     else if (mIsMovingDown)
//     {
//         movement.y += speed;
//     }
//     else if (mIsMovingLeft)
//     {
//         movement.x -= speed;
//     }
//     else if (mIsMovingRight)
//     {
//         movement.x += speed;
//     }

//     mSnake.move(movement * deltaTime.asSeconds());

//     if (mSnake.getPosition().x < 0 || mSnake.getPosition().x > mWindow.getSize().x - mSnake.getSize().x || mSnake.getPosition().y < 0 || mSnake.getPosition().y > mWindow.getSize().y - mSnake.getSize().y)
//     {
//         mWindow.close();
//     }
// }

// void Game::reder()
// {
//     mWindow.clear();
//     mWindow.draw(mSnake);
//     mWindow.display();
// }
#include "game.hpp"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
    : mWindow(sf::VideoMode(800, 600), "Snake Game")
    , mSnake()
    , mIsMovingUp(false)
    , mIsMovingDown(false)
    , mIsMovingRight(false)
    , mIsMovingLeft(false)
{
    mWindow.setKeyRepeatEnabled(false);
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
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

void Game::handlePlayerInput(sf::Keyboard::Key key)
{
    if (key == sf::Keyboard::Up && !mIsMovingDown)
    {
        mIsMovingUp = true;
        mIsMovingRight = false;
        mIsMovingLeft = false;
    }
    else if (key == sf::Keyboard::Down && !mIsMovingUp)
    {
        mIsMovingDown = true;
        mIsMovingRight = false;
        mIsMovingLeft = false;
    }
    else if (key == sf::Keyboard::Left && !mIsMovingRight)
    {
        mIsMovingLeft = true;
        mIsMovingUp = false;
        mIsMovingDown = false;
    }
    else if (key == sf::Keyboard::Right && !mIsMovingLeft)
    {
        mIsMovingRight = true;
        mIsMovingUp = false;
        mIsMovingDown = false;
    }
}

void Game::update(sf::Time deltaTime)
{
    const float speed = 100.f;

    sf::Vector2f movement(0.f, 0.f);

    if (mIsMovingUp)
    {
        movement.y -= speed;
    }
    else if (mIsMovingDown)
    {
        movement.y += speed;
    }
    else if (mIsMovingLeft)
    {
        movement.x -= speed;
    }
    else if (mIsMovingRight)
    {
        movement.x += speed;
    }

    mSnake.move(movement * deltaTime.asSeconds());

    if (mSnake.getPosition().x < 0 || mSnake.getPosition().x > mWindow.getSize().x - mSnake.getSize().x || mSnake.getPosition().y < 0 || mSnake.getPosition().y > mWindow.getSize().y - mSnake.getSize().y)
    {
        mWindow.close();
    }
}

void Game::reder()
{
    mWindow.clear();
    mWindow.draw(mSnake);
    mWindow.display();
}


