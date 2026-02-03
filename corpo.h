#ifndef CORPO_H
#define CORPO_H

#include <SFML/Graphics.hpp>

// Representa um segmento do corpo da cobra.
// Cada `Corpo` é uma célula retangular que sabe desenhar-se,
// mover-se (deslocamento) e aplicar comportamento de borda.
class Corpo{
public:
    sf::RectangleShape formato; // forma e propriedades visuais do segmento
    Corpo(float x, float y);
    void Draw(sf::RenderWindow &window); // desenha o segmento na janela
    void Move(sf::Vector2f dir); // move o segmento pela direção fornecida
    void bordas(float &x,float &y,float largura, float altura); // aplica wrap nas bordas
};


#endif