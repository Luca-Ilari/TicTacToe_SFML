#include <SFML/Graphics.hpp>

#ifndef TESTSFML_SPRITES_H
#define TESTSFML_SPRITES_H

class CustomSprite : public sf::Drawable{
private:
    float x;
    float y;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    CustomSprite();
    CustomSprite(float x, float y);
    virtual void move(float newX, float newY);
    float getX() const;
    float getY() const;
    virtual std::string type();
};

#endif //TESTSFML_SPRITES_H