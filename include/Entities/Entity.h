#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <stack>
#include <map>

#include <SFML/Graphics.hpp>

class Entity
{
private:
    void initVariables();

protected:
    sf::Texture* texture;
    sf::Sprite* sprite;

    float movementSpeed;

public:
    Entity();
    virtual ~Entity();

    void createSprite(sf::Texture* texture);

    virtual void setPosition(const float x, const float y);
    virtual void move(const float& dt, const float x, const float y);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};

#endif // ENTITY_H
