#ifndef PLACAR_H
#define PLACAR_H

#include <SFML/Graphics.hpp>
#include <string>
// Placar: gerencia fontes, texto e valor da pontuação exibida na tela
class Placar{
public:
    int pontuacao=0; // valor atual da pontuação
    sf::Font fonte; // fonte para o rótulo
    sf::Font fonte2; // fonte para o valor numérico
    sf::Text texto; // texto do rótulo (ex: "POINTS")
    sf::Text texto2; // texto do valor da pontuação
    Placar();
    void Draw(sf::RenderWindow &window); // desenha o placar
    void atualizarPontuacao(); // atualiza o texto do valor com `pontuacao`
};



#endif