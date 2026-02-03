#ifndef FUNDO_H
#define FUNDO_H

#include <SFML/Graphics.hpp>
// Responsável pelo fundo/placa do jogo (área de jogo e background)
class Fundo{
public:
    sf::RectangleShape fundo;  // área principal do jogo
    sf::RectangleShape fundo2; // camada de fundo inteira
    Fundo();
    void Draw(sf::RenderWindow &window); // desenha as camadas do fundo

};
#endif