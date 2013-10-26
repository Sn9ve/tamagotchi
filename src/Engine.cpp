#include "Engine.hpp"

#include "Game.hpp"

#include "Game_engine.hpp"
#include "Graphics_engine.hpp"
#include "Audio_engine.hpp"
#include "Network_engine.hpp"

Engine::Engine(Game *parent) :
    m_parent(parent),
    m_eGame(nullptr),
    m_eGraphics(nullptr),
    m_eAudio(nullptr),
    m_eNetwork(nullptr)
{
}

Engine::~Engine()
{
}

void Engine::push_event(Engine_event &e)
{
    m_events.push(e);
}

void Engine::process_queue()
{
    while(!m_events.empty())
    {
        Engine_event e = m_events.front();
        m_events.pop();

        process_event(e);
    }
}

void Engine::attach_Game_engine(std::shared_ptr<Game_engine> eGame)
{
    m_eGame = eGame;
}

void Engine::attach_Graphics_engine(std::shared_ptr<Graphics_engine> eGraphics)
{
    m_eGraphics = eGraphics;
}

void Engine::attach_Audio_engine(std::shared_ptr<Audio_engine> eAudio)
{
    m_eAudio = eAudio;
}

void Engine::attach_Network_engine(std::shared_ptr<Network_engine> eNetwork)
{
    m_eNetwork = eNetwork;
}
