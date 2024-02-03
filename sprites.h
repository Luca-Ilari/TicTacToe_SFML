#include <SFML/Graphics.hpp>

#ifndef TESTSFML_SPRITES_H
#define TESTSFML_SPRITES_H

class Sprite : public sf::Drawable{
private:
    float x;
    float y;

public:
    Sprite(float x, float y);
    virtual void move(float newX, float newY);
    float getX() const;
    float getY() const;
};

class circleSprite : public Sprite {
private:
    sf::CircleShape circle;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    circleSprite(float x, float y, float r);
    void move(float newX, float newY) override;
};

class crossSprite : public Sprite {
private:
    sf::Vertex cross[4] = {
            sf::Vertex(sf::Vector2f()),
            sf::Vertex(sf::Vector2f()),
            sf::Vertex(sf::Vector2f()),
            sf::Vertex(sf::Vector2f()),
    };
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    crossSprite(float x, float y);
};
#endif //TESTSFML_SPRITES_H