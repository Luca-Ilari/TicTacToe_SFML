#include "Sprites.h"

#ifndef TICTACTOE_SFML_CROSSSPRITE_H
#define TICTACTOE_SFML_CROSSSPRITE_H

class CrossSprite : public CustomSprite{
private:
    sf::Vertex cross[4] = {
            sf::Vertex(sf::Vector2f(0, 0)),
            sf::Vertex(sf::Vector2f(80, 80)),
            sf::Vertex(sf::Vector2f(80, 0)),
            sf::Vertex(sf::Vector2f(0, 80)),
    };
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    CrossSprite(float x, float y);
    std::string type() override;
};

#endif //TICTACTOE_SFML_CROSSSPRITE_H
