#include "Graphics_engine.hpp"

#include "Game.hpp"

Graphics_engine::Graphics_engine(Game *parent) :
    Engine(parent),
    m_sprites([](std::pair<const sf::Drawable&,unsigned> a,std::pair<const sf::Drawable&,unsigned> b){return a.second > b.second;})
{
}

void Graphics_engine::draw(const sf::Drawable &drawnable, unsigned plan)
{
    m_sprites.insert({drawnable,plan});
}

void Graphics_engine::frame()
{
    if(m_window.isOpen())
    {
        sf::Event event;
        // tant qu'il y a des évènements à traiter...
        while (m_window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                m_parent->stop();
                break;

            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                case sf::Keyboard::Escape:
                    m_window.close();
                    m_parent->stop();
                    break;

                default:
                    break;
                }
                break;

            default:
                break;
            }
        }

        m_window.clear();

        for(const auto &sp : m_sprites)
            m_window.draw(sp.first);

        m_window.display();
        m_sprites.clear();
    }
}

void Graphics_engine::openWindow()
{
    m_window.create(sf::VideoMode(800,600), "Tamagotchi", sf::Style::Default);
}

void Graphics_engine::process_event(Engine_event &e)
{

}
