#include "Entity.h"

void Entity::initVariables()
{

}

Entity::Entity()
{

}

Entity::~Entity()
{
    //dtor
}

void Entity::createSprite(sf::Texture* texture)
{
    this->texture = texture;
    this->sprite->setTexture(*this->texture);
}

void Entity::setPosition(const float x, const float y)
{
    this->sprite->setPosition(x, y);
}

void Entity::move(const float& dt, const float x, const float y)
{
    this->sprite->move(x * this->movementSpeed * dt, y * this->movementSpeed * dt);
}

void Entity::update(const float& dt)
{

}

void Entity::render(sf::RenderTarget* target)
{
    target->draw(*this->sprite);
}

