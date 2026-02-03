#include "fundo.h"
// Inicializa as formas que compõem o fundo do jogo
Fundo::Fundo(){
    fundo.setSize(sf::Vector2f(448,432));
    fundo.setFillColor(sf::Color(132, 164, 108));
    fundo.setPosition(16,48);
    fundo.setOutlineThickness(3.f);
    fundo.setOutlineColor(sf::Color(4,51,43));

    fundo2.setSize(sf::Vector2f(480,496));
    fundo2.setFillColor(sf::Color(132, 164, 108));
    fundo2.setPosition(0,0);

}

// Desenha primeiro a camada de fundo completa e depois a área de jogo
void Fundo::Draw(sf::RenderWindow &window){
    window.draw(this->fundo2);
    window.draw(this->fundo);
}