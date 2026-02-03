#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "corpo.h"
#include <random>
// Classe que representa a cobra inteira como um vetor de `Corpo`.
// Responsável por desenhar, movimentar, crescer e detectar colisões.
class Snake{
private:
    std::vector <Corpo> body; // segmentos, índice 0 é a cabeça
public:
    Snake(float x0, float y0); // cria cobra com uma célula inicial
    void Draw(sf::RenderWindow& window); // desenha todos os segmentos
    void Move(sf::Vector2f dir); // atualiza posições dos segmentos
    void bordas(float &x, float &y, float largura, float altura); // delega tratamento de bordas para a cabeça
    void comer(); // adiciona um novo segmento (crescimento)
    bool colisao(); // verifica colisão da cabeça com o próprio corpo
    sf::Vector2f getPosition(); // posição da cabeça
    sf::Vector2f getSegmentPosition(int index); // posição de um segmento específico
    int getBodySize(); // número de segmentos
};
#endif