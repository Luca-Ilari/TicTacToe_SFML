#include <SFML/Graphics.hpp>
#include "Sprites.h"

CustomSprite::CustomSprite(float x, float y) : x(x), y(y) {
    this->x = x;
    this->y = y;
}
CustomSprite::CustomSprite() {
    this-> x = 0;
    this-> y = 0;
}
void CustomSprite::move(float newX, float newY) {
    this->x = newX;
    this->y = newY;
}
float CustomSprite::getX() const {
    return x;
}
float CustomSprite::getY() const {
    return y;
}
void CustomSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
}
std::string CustomSprite::type() {
    return "CustomSprite";
}