#ifndef GRAPHICS_ENGINE_HPP
#define GRAPHICS_ENGINE_HPP

#include "Engine.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class Graphics_engine : public Engine
{
public:
    Graphics_engine(Game *parent);
    virtual void frame();
    void openWindow();

protected:
    virtual void process_event(Engine_event &e);

    sf::RenderWindow m_window;
};

#endif // GRAPHICS_ENGINE_HPP
