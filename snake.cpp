#include "snake.h"

Snake::Snake(float x0, float y0){
    body.emplace_back(x0, y0);
}
void Snake::Draw(sf::RenderWindow& window){
    for (auto& parte : body) {
       parte.Draw(window);
    }
}
void Snake::Move(sf::Vector2f dir){
    // Guarda posições anteriores (de trás para frente)
    sf::Vector2f temp_pos = body[0].formato.getPosition();
    body[0].Move(dir); // Move a cabeça
    
    // Cada segmento vai para a posição do anterior
    for (int i = 1; i < body.size(); i++) {
        sf::Vector2f nova_pos = body[i].formato.getPosition();
        body[i].formato.setPosition(temp_pos);
        temp_pos = nova_pos;
    }
}
void Snake:: bordas(float &x, float &y, float largura, float altura){
    body[0].bordas(x,y,largura,altura);
}
void Snake::comer(){
    // Adiciona novo segmento na posição da cauda (último segmento)
    sf::Vector2f cauda_pos = body.back().formato.getPosition();
    body.emplace_back(cauda_pos.x, cauda_pos.y);
}
bool Snake::colisao(){
    for(int i=3; i<body.size();i++){
        if (body[0].formato.getPosition()==body[i].formato.getPosition()){
            return true;
        }
    }
    return false;
}

sf::Vector2f Snake::getPosition(){
    return body[0].formato.getPosition();
}

sf::Vector2f Snake::getSegmentPosition(int i){
    if(i >= 0 && i < body.size()){
        return body[i].formato.getPosition();
    }
    return sf::Vector2f(0, 0);
}

int Snake::getBodySize(){
    return body.size();
}

//mudar comer para food, e ter uma em snak pontuacaoe para subir e tamanho da cobra
