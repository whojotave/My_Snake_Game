#ifndef CORPO_H
#define CORPO_H

#include <SFML/Graphics.hpp>

class Corpo{
public:
    sf::RectangleShape formato;
    Corpo(float x, float y);
    void Draw(sf::RenderWindow &window);
    void Move(sf::Vector2f dir);
    void bordas(float &x,float &y,float largura, float altura);
};


#endif