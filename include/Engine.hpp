#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>
#include <queue>
#include "Engine_event.hpp"

class Game;

class Game_engine;
class Graphics_engine;
class Audio_engine;
class Network_engine;

class Engine
{
public:
    Engine(Game *parent);
    virtual ~Engine();
    void push_event(Engine_event &e);
    void process_queue();
    virtual void frame() = 0;

    void attach_Game_engine(std::shared_ptr<Game_engine> eGame);
    void attach_Graphics_engine(std::shared_ptr<Graphics_engine> eGraphics);
    void attach_Audio_engine(std::shared_ptr<Audio_engine> eAudio);
    void attach_Network_engine(std::shared_ptr<Network_engine> eNetwork);

protected:
    Game *m_parent;

    std::shared_ptr<Game_engine> m_eGame;
    std::shared_ptr<Graphics_engine> m_eGraphics;
    std::shared_ptr<Audio_engine> m_eAudio;
    std::shared_ptr<Network_engine> m_eNetwork;

    std::queue<Engine_event> m_events;

    virtual void process_event(Engine_event &e) = 0;
};

#endif // ENGINE_HPP
