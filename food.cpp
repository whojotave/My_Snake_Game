#include "food.h"

Food::Food(float x, float y){
    food.setSize(sf::Vector2f(16,16));
    food.setFillColor(sf::Color::Red);
    food.setPosition(x,y);
}
void Food::Draw(sf::RenderWindow &window){
    window.draw(this->food);
}
void Food::comer(Snake &s){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 28);
    std::uniform_int_distribution<int> dist2(3, 28);
    
    float x = 16 * dist(gen);
    float y = 16 * dist2(gen);
    
    bool colidiu = true;
    while(colidiu){
        x = 16 * dist(gen);
        y = 16 * dist2(gen);
        colidiu = false;
        
        // Verifica se a comida colide com qualquer parte do corpo
        for(int i = 0; i < s.getBodySize(); i++){
            sf::Vector2f bodyPos = s.getSegmentPosition(i);
            float bodyX = bodyPos.x;
            float bodyY = bodyPos.y;
            
            if(std::fabs(x - bodyX) < 16 && std::fabs(y - bodyY) < 16){
                colidiu = true;
                break;
            }
        }
    }
    
    food.setPosition(x, y);
}

sf::Vector2f Food::getPosition(){
    return food.getPosition();
}