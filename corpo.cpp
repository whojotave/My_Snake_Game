#include "corpo.h"

// Construtor: inicializa o retângulo que representa o segmento
Corpo::Corpo(float x, float y){
    formato.setSize(sf::Vector2f(16,16));
    formato.setFillColor(sf::Color(4,51,43));
    formato.setPosition(x,y);
    formato.setOutlineThickness(1.f);
    formato.setOutlineColor(sf::Color(132,164,108));
}

// Desenha o segmento na janela SFML
void Corpo::Draw(sf::RenderWindow &window){
    window.draw(this->formato);
}

// Move o segmento aplicando um deslocamento (usado para atualizar posição)
void Corpo::Move(sf::Vector2f dir){
    formato.move(dir);
}

// Tratamento de bordas: faz wrap-around quando o segmento sai da área
void Corpo::bordas(float &x,float &y,float largura, float altura){
    sf::Vector2f pos = formato.getPosition();
    
    if(pos.x<16) pos.x=largura-32;
    if(pos.x>largura-32) pos.x=16;
    if(pos.y<48) pos.y=altura-32;
    if(pos.y>altura-32) pos.y=48;
    
    formato.setPosition(pos);
}
