#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states)
{
    this->quit = false;
    this->window = window;
    this->states = states;
}

State::~State()
{
    //dtor
}

void State::updateMousePositions()
{
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
