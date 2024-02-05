#include <SFML/Graphics.hpp>

#ifndef TESTSFML_SPRITES_H
#define TESTSFML_SPRITES_H

class Sprite : public sf::Drawable{
private:
    float x;
    float y;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    Sprite();
    Sprite(float x, float y);
    virtual void move(float newX, float newY);
    float getX() const;
    float getY() const;
    virtual std::string type();
};

class circleSprite : public Sprite {
private:
    float r;
    sf::CircleShape circle;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    circleSprite(float x, float y);
    void move(float newX, float newY) override;
    std::string type() override;
};

class crossSprite : public Sprite{
private:
    sf::Vertex cross[4] = {
            sf::Vertex(sf::Vector2f(0, 0)),
            sf::Vertex(sf::Vector2f(80, 80)),
            sf::Vertex(sf::Vector2f(80, 0)),
            sf::Vertex(sf::Vector2f(0, 80)),
    };
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    crossSprite(float x, float y);
    std::string type() override;
};
#endif //TESTSFML_SPRITES_H