#include "placar.h"
// Inicializa fontes e textos do placar
Placar::Placar(){
    fonte.loadFromFile("interface/fontes/Zepter_Pro.ttf");
    fonte2.loadFromFile("interface/fontes/Digit.TTF");
    texto.setFont(fonte);
    texto2.setFont(fonte2);
    texto.setString("POINTS");
    texto2.setString(std::to_string (this->pontuacao));
    texto.setCharacterSize(16);
    texto2.setCharacterSize(20);
    texto.setFillColor(sf::Color(4,51,43));
    texto2.setFillColor(sf::Color(4,51,43));
    texto.setPosition(0,0);
    texto2.setPosition(0,16);

}

// Desenha o rótulo e o valor da pontuação
void Placar::Draw(sf::RenderWindow &window){
    window.draw(this->texto);
    window.draw(this->texto2);
}

// Atualiza texto do valor com o valor atual de `pontuacao`
void Placar::atualizarPontuacao(){
    texto2.setString(std::to_string(this->pontuacao));
}