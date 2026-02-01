#ifndef FUNDO_H
#define FUNDO_H

#include <SFML/Graphics.hpp>

class Fundo{
public:
    sf::RectangleShape fundo;
    sf::RectangleShape fundo2;
    Fundo();
    void Draw(sf::RenderWindow &window);

};
#endif