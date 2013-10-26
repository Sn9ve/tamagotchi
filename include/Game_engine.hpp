#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include "Engine.hpp"
#include <memory>

#include <SFML/Graphics.hpp>
class Game_engine : public Engine
{
public:
    Game_engine(Game *parent);
    virtual void frame();

protected:
    virtual void process_event(Engine_event &e);
};

#endif // GAME_ENGINE_HPP
