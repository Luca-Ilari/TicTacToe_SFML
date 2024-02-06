#include "Sprites.h"

#ifndef TICTACTOE_SFML_CIRCLESPRITE_H
#define TICTACTOE_SFML_CIRCLESPRITE_H

class CircleSprite : public CustomSprite {
private:
    float r;
    sf::CircleShape circle;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    CircleSprite(float x, float y);
    void move(float newX, float newY) override;
    std::string type() override;
};

#endif //TICTACTOE_SFML_CIRCLESPRITE_H
