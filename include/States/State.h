#ifndef STATE_H
#define STATE_H

#include "Entity.h"
#include "ResourceManager.h"

class State
{
protected:
    std::stack<State*>* states;
    sf::RenderWindow* window;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    bool quit;

public:
    State(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~State();

    bool getQuit() { return this->quit; }

    virtual void endState() = 0;

    virtual void updateMousePositions();
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif // STATE_H
