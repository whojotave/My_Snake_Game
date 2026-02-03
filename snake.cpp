#include "snake.h"
// Construtor: cria a cobra com um segmento inicial (a cabeça)
Snake::Snake(float x0, float y0){
    body.emplace_back(x0, y0);
}

// Desenha todos os segmentos da cobra
void Snake::Draw(sf::RenderWindow& window){
    for (auto& parte : body) {
       parte.Draw(window);
    }
}

// Move a cabeça na direção `dir` e faz cada segmento seguir o anterior
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

// Encaminha a rotina de bordas para o primeiro segmento (cabeça)
void Snake:: bordas(float &x, float &y, float largura, float altura){
    body[0].bordas(x,y,largura,altura);
}

// Adiciona um novo segmento na posição atual da cauda (crescimento)
void Snake::comer(){
    sf::Vector2f cauda_pos = body.back().formato.getPosition();
    body.emplace_back(cauda_pos.x, cauda_pos.y);
}

// Verifica se a cabeça colidiu com algum segmento do próprio corpo
bool Snake::colisao(){
    for(int i=3; i<body.size();i++){
        if (body[0].formato.getPosition()==body[i].formato.getPosition()){
            return true;
        }
    }
    return false;
}

// Retorna posição da cabeça
sf::Vector2f Snake::getPosition(){
    return body[0].formato.getPosition();
}

// Retorna posição de um segmento por índice, ou (0,0) se inválido
sf::Vector2f Snake::getSegmentPosition(int i){
    if(i >= 0 && i < body.size()){
        return body[i].formato.getPosition();
    }
    return sf::Vector2f(0, 0);
}

// Número de segmentos da cobra
int Snake::getBodySize(){
    return body.size();
}

// OBS: comentários de TODO podem permanecer no código para melhorias futuras
