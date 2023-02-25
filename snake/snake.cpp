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
    void Snake::move()
    {         // Movethe body blocks from the tail towards the head
    
    for(int i = m_blocks.size() -1; i>0; --i){
       m_blocks[i].setPosition(m_blocks[i-1].getPosition());
    }
     m_blocks[0].move(m_velocity);
    }