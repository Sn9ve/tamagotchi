#ifndef GRAPHICS_ENGINE_HPP
#define GRAPHICS_ENGINE_HPP

#include "Engine.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <set>

class Graphics_engine : public Engine
{
public:
    Graphics_engine(Game *parent);
    virtual void frame();
    void openWindow();
    void draw(const sf::Drawable &drawnable, unsigned plan);

protected:
    virtual void process_event(Engine_event &e);

    sf::RenderWindow m_window;
    std::set<std::pair<const sf::Drawable&,unsigned>, bool(*)(std::pair<const sf::Drawable&,unsigned>,std::pair<const sf::Drawable&,unsigned>)> m_sprites;
};

#endif // GRAPHICS_ENGINE_HPP
