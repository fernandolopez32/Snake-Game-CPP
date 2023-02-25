#include "snake.hpp"

Snake :: Snake(float block_size,sf::Color color)
    :m_block_size(block_size)
    ,m_color(color)
    ,m_velocity(block_size,0)
    {
// Initialize the snake with three blocks
        for(int i = 0; i < 3; i++){
            sf::RectangleShape block(sf::Vector2f(m_block_size,m_block_size));
            block.setPosition((3-i)*m_block_size,0);
            block.setFillColor(m_color);
            m_blocks.push_back(block);
        }
    }
// snake movement
    void Snake::move()
    {         // Movethe body blocks from the tail towards the head
    
    for(int i = m_blocks.size() -1; i>0; --i){
       m_blocks[i].setPosition(m_blocks[i-1].getPosition());
    }   
    //move the head block in the current direction
     m_blocks[0].move(m_velocity);
    }
//snake growth

    void Snake::grow()
    {
        //add a new block to the end of the snake
        sf::RectangleShape block(sf::Vector2f(m_block_size,m_block_size));
        block.setPosition(m_blocks.back().getPosition());
        block.setFillColor(m_color);
        m_blocks.push_back(block);
    }
// redering the snake 
    void Snake::reder(sf::RenderWindow& window)
    {
        //render all the blocks of the snake
        for(const auto& block : m_blocks){
            window.draw(block);
        }
    }
// self colision terminatin of game clause 
    bool Snake:: is_colliding_with_self () const
    {
        //check if the head block is colliding with any of the body blocks 
        for(int i =1; i <m_blocks.size(); ++i){
            if(m_blocks[0].getGlobalBounds().intersects(m_blocks[i].getGlobalBounds())){
                return true;
            }
        }
        return false;
    }

//colissoin with the out of bounds 

    bool Snake::is_colliding_with_wall(float window_width, float window_height) const
    {
        // check i the head block is colliding with any of the windows boundaries
        float x = m_blocks[0].getPosition().x;
        float y = m_blocks[0].getPosition().y;
        return (x<0 || x+ m_block_size > window_width || y < 0 || y + m_block_size > window_height);
    }