#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include <random>
#include "snake.h"

class Food{
public:
    sf::RectangleShape food;
    Food(float x, float y);
    void Draw(sf::RenderWindow &window);
    void comer(Snake &s);
    sf::Vector2f getPosition();
};
#endif