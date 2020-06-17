#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState : public State
{
private:
    sf::RectangleShape shape;

    ResourceManager stateResources;

    sf::Sprite testSprite;

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    ~GameState();

    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};

#endif // GAMESTATE_H
