#include "CrossSprite.h"
#include "Sprites.h"

CrossSprite::CrossSprite(float x, float y) : CustomSprite(x, y) {
    //Transform vertex of the cross to they relative position
    for (int i = 0; i < 4; ++i) {
        cross[i].position.x += x-40; // -40 necessary for converting of the
        cross[i].position.y += y-40;
    }
}
void CrossSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(cross, 4, sf::Lines);
}
std::string CrossSprite::type() {
    return "CrossSprite";
}
