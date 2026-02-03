#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include <random>
#include "snake.h"
// Representa a comida que a cobra pode comer.
// A comida é reposicionada aleatoriamente, evitando colisão com o corpo.
class Food{
public:
    sf::RectangleShape food; // forma visual da comida
    Food(float x, float y);
    void Draw(sf::RenderWindow &window); // desenha a comida
    void comer(Snake &s); // reposiciona comida garantindo que não colida com a cobra
    sf::Vector2f getPosition(); // retorna posição atual
};
#endif