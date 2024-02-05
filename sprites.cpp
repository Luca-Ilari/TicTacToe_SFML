#include <SFML/Graphics.hpp>
#include "sprites.h"

Sprite::Sprite(float x, float y) : x(x), y(y) {
    this->x = x;
    this->y = y;
}
Sprite::Sprite() {
    this-> x = 0;
    this-> y = 0;
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
void Sprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
}
std::string Sprite::type() {
    return "Sprite";
}

circleSprite::circleSprite(float x, float y) : Sprite(x, y) {
    this->r = 40;
    circle.setOrigin(r,r);
    circle.setPosition(x,y);
    circle.setRadius(r);
    circle.setOutlineThickness(1);
    circle.setFillColor(sf::Color::Black);
}
void circleSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(circle, states);
}
void circleSprite::move(float newX, float newY) {
    Sprite::move(newX, newY);
    circle.setPosition(newX,newY);
}
std::string circleSprite::type() {
    return "circleSprite";
}

crossSprite::crossSprite(float x, float y) : Sprite(x, y) {
    //Transform vertex of the cross to they relative position
    for (int i = 0; i < 4; ++i) {
       cross[i].position.x += x-40; // -40 necessary for converting of the
       cross[i].position.y += y-40;
    }
}
void crossSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(cross, 4, sf::Lines);
}
std::string crossSprite::type() {
    return "crossSprite";
}
