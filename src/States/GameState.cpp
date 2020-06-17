#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
    this->shape.setSize(sf::Vector2f(50.f, 50.f));

    if (!stateResources.textures["IDLE"].loadFromFile("res/texture.png"))
    {
        std::cout << "failed to load dk";
    }

    if (!stateResources.soundBuffers["SOUND_BUFFER"].loadFromFile("res/sound.ogg"))
    {
        std::cout << "failed to lool" << std::endl;
    }

    if (!stateResources.fonts["FONT"].loadFromFile("res/font.otf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    stateResources.sounds["SOUND"].setBuffer(stateResources.soundBuffers["SOUND_BUFFER"]);

    this->testSprite.setTexture(stateResources.textures["IDLE"]);
    this->testSprite.setPosition(100, 100);
}

GameState::~GameState()
{
    //dtor
}

void GameState::endState()
{
    std::cout << "ending gs" << std::endl;
}

void GameState::updateInput(const float& dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->quit = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
        stateResources.sounds["SOUND"].play();
}

void GameState::update(const float& dt)
{
    this->updateInput(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    target->draw(this->testSprite);
}
