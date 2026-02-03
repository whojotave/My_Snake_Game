

#include <iostream>
#include <SFML/Graphics.hpp>
#include "snake.h"
#include "food.h"
#include "interface/fundo.h"
#include "interface/placar.h"

// main.cpp
// Ponto de entrada do jogo "Snake Game".
// Contém a inicialização da janela SFML, o laço principal do jogo,
// leitura de input do teclado, atualização do estado (cobra, comida,
// placar) e renderização das entidades.
int main()
{

    float largura = 480;
    float altura = 496;
    float snakeX = 240;
    float snakeY = 240;
    float movimento =16;
    float foodX=96;
    float foodY=96;

    Snake s(snakeX, snakeY);
    Food f(foodX,foodY);
    Fundo fundo;
    Placar p;
    std::string winName = "Snake Game";
    sf::RenderWindow window(sf::VideoMode(largura, altura), winName);
    window.setFramerateLimit(60);
    sf::Vector2f dir(movimento, 0);
    sf::Clock clock;
    float velocidade = 0.1f; // em segundos - movimento mais lento
    while (window.isOpen())
    {
        sf::Event e;

        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        int keyCount = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) keyCount++;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) keyCount++;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) keyCount++;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) keyCount++;

        if (keyCount == 1)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && dir.y == 0)
            {
                dir = sf::Vector2f(0, -movimento);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && dir.x == 0)
            {
                dir = sf::Vector2f(-movimento, 0);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && dir.x == 0)
            {
                dir = sf::Vector2f(+movimento, 0);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && dir.y == 0)
            {
                dir = sf::Vector2f(0, +movimento);
            }
        }
        
        // Controla velocidade do movimento com clock
        if (clock.getElapsedTime().asSeconds() >= velocidade)
        {
            s.Move(dir);
            clock.restart();
        }
        
        s.bordas(snakeX,snakeY,largura,altura);
        if(s.colisao()){
            window.close();
        }
        
        
        snakeX = s.getPosition().x;
        snakeY = s.getPosition().y;
        foodX = f.getPosition().x;
        foodY = f.getPosition().y;
        
        if(snakeX==foodX&&snakeY==foodY){
            f.comer(s);
            s.comer();
            p.pontuacao+=5;
            p.atualizarPontuacao();
        }
        
        
        window.clear();
        fundo.Draw(window);
        s.Draw(window);
        f.Draw(window);
        p.Draw(window);
        window.display();
    }
}

