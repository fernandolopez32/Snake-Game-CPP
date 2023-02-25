#ifndef SNAKE_HPP
#define SNAKE_HPP 

#include <SFML/Graphics.hpp>

class Snake{
    public:
        snake(float block_size, sf::Color color);
        void move();
        void grow();
        void reder(sf::RenderWindow& window);
        bool is_colliding_with_self() const;
        bool is_colliding_with_wall(float window_width, float window_height)const;
    private:
        std::vector<sf::RectangleShape> m_blocks;
        float m_block_size;
        sf::Color m_color;
        sf::Vector2f m_velocity;

    
};

#endif