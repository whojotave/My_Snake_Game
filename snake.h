#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "corpo.h"
#include <random>

class Snake{
private:
    std::vector <Corpo> body;
public:
    Snake(float x0, float y0);
    void Draw(sf::RenderWindow& window);
    void Move(sf::Vector2f dir);
    void bordas(float &x, float &y, float largura, float altura);
    void comer();
    bool colisao();
    sf::Vector2f getPosition();
    sf::Vector2f getSegmentPosition(int index);
    int getBodySize();
};
#endif