#include <SFML/Graphics.hpp>
#include "CircleSprite.h"
#include "Sprites.h"

CircleSprite::CircleSprite(float x, float y) : CustomSprite(x, y) {
    this->r = 40;
    circle.setOrigin(r,r);
    circle.setPosition(x,y);
    circle.setRadius(r);
    circle.setOutlineThickness(1);
    circle.setFillColor(sf::Color::Black);
}
void CircleSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(circle, states);
}
void CircleSprite::move(float newX, float newY) {
    CustomSprite::move(newX, newY);
    circle.setPosition(newX,newY);
}
std::string CircleSprite::type() {
    return "circleSprite";
}