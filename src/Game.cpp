#include "Game.hpp"

#include "Game_engine.hpp"
#include "Graphics_engine.hpp"
#include "Audio_engine.hpp"
#include "Network_engine.hpp"

Game::Game() :
    m_stillRunning(false)
{
    m_eGame = std::make_shared<Game_engine>(this);
    m_eGraphics = std::make_shared<Graphics_engine>(this);
    m_eAudio = std::make_shared<Audio_engine>(this);
    m_eNetwork = std::make_shared<Network_engine>(this);

    m_eGame->attach_Graphics_engine(m_eGraphics);
    m_eGame->attach_Audio_engine(m_eAudio);
    m_eGame->attach_Network_engine(m_eNetwork);

    m_eGraphics->attach_Game_engine(m_eGame);
    m_eGraphics->attach_Audio_engine(m_eAudio);
    m_eGraphics->attach_Network_engine(m_eNetwork);

    m_eAudio->attach_Game_engine(m_eGame);
    m_eAudio->attach_Graphics_engine(m_eGraphics);
    m_eAudio->attach_Network_engine(m_eNetwork);

    m_eNetwork->attach_Game_engine(m_eGame);
    m_eNetwork->attach_Graphics_engine(m_eGraphics);
    m_eNetwork->attach_Audio_engine(m_eAudio);
}

int Game::run()
{
    m_eGraphics->openWindow();
    m_stillRunning = true;
    while(m_stillRunning)
    {
        m_eGame->frame();
        m_eGraphics->frame();
        m_eAudio->frame();
        m_eNetwork->frame();
    }
    return 0;
}

void Game::stop()
{
    m_stillRunning = false;
}
