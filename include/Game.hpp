#ifndef GAME_HPP
#define GAME_HPP

#include <memory>

class Game_engine;
class Graphics_engine;
class Audio_engine;
class Network_engine;

class Game
{
public:
    Game();
    int run();
    void stop();

private:
    bool m_stillRunning;
    std::shared_ptr<Game_engine> m_eGame;
    std::shared_ptr<Graphics_engine> m_eGraphics;
    std::shared_ptr<Audio_engine> m_eAudio;
    std::shared_ptr<Network_engine> m_eNetwork;
};

#endif // GAME_HPP
