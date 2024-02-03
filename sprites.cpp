#include <SFML/Graphics.hpp>
#include "sprites.h"

Sprite::Sprite(float x, float y) : x(x), y(y) {
    this->x = x;
    this->y = y;
}
void Sprite::move(float newX, float newY) {
    this->x = newX;
    this->y = newY;
}
float Sprite::getX() const {
    return x;
}
float Sprite::getY() const {
    return y;
}

circleSprite::circleSprite(float x, float y, float r) : Sprite(x, y) {
    circle.setPosition(x,y);
    circle.setRadius(r);
}
void circleSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(circle, states);
}
void circleSprite::move(float newX, float newY) {
    Sprite::move(newX, newY);
    circle.setPosition(newX,newY);
}

crossSprite::crossSprite(float x, float y) : Sprite(x, y) {
    //Transform vertex of the cross to they relative position
    for (int i = 0; i < 4; ++i) {

    }
}
void crossSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(cross, 4, sf::Lines);
}
