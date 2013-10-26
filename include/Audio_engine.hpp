#ifndef AUDIO_ENGINE_HPP
#define AUDIO_ENGINE_HPP

#include "Engine.hpp"
#include <SFML/Audio.hpp>
#include <memory>

class Game_engine;
class Graphics_engine;
class Network_engine;

class Audio_engine : public Engine
{
public:
    Audio_engine(Game *parent);
    virtual void frame();

protected:
    virtual void process_event(Engine_event &e);
};

#endif // AUDIO_ENGINE_HPP
