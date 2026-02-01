#ifndef PLACAR_H
#define PLACAR_H

#include <SFML/Graphics.hpp>
#include <string>
class Placar{
public:
    int pontuacao=0;
    sf::Font fonte;
    sf::Font fonte2;
    sf::Text texto;
    sf::Text texto2;
    Placar();
    void Draw(sf::RenderWindow &window);
    void atualizarPontuacao();
};



#endif