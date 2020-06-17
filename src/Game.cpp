#include "Game.h"

void Game::initWindow()
{
    //Create your window
    this->window = new sf::RenderWindow(sf::VideoMode(1000, 800), "Game Title");
}

void Game::initStates()
{
    this->states.push(new GameState(this->window, &this->states));
}

Game::Game()
{
    this->initWindow();
    this->initStates();
}

Game::~Game()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

void Game::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateEvents()
{
    while (this->window->pollEvent(this->event))
    {
        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateDt();
    this->updateEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
}

void Game::render()
{
    this->window->clear();

    if (!this->states.empty())
        this->states.top()->render(this->window);

    this->window->display();
}

void Game::run()
{
    while (window->isOpen())
    {
        this->update();
        this->render();
    }
}
