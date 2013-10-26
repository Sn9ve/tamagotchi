#include "Graphics_engine.hpp"

#include "Game.hpp"

Graphics_engine::Graphics_engine(Game *parent) :
    Engine(parent)
{
}

void Graphics_engine::frame()
{

    sf::Event event;

    // tant qu'il y a des évènements à traiter...
    while (m_window.pollEvent(event))
    {
        // on regarde le type de l'évènement...
        switch (event.type)
        {
        // fenêtre fermée
        case sf::Event::Closed:
            m_window.close();
            m_parent->stop();
            break;

            // touche pressée
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

            // on ne traite pas les autres types d'évènements
        default:
            break;
        }
    }

    m_window.clear();

    m_window.display();

}

void Graphics_engine::openWindow()
{
    m_window.create(sf::VideoMode(800,600), "smu", sf::Style::Default);
}

void Graphics_engine::process_event(Engine_event &e)
{

}
