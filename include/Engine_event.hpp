#ifndef ENGINE_EVENT_HPP
#define ENGINE_EVENT_HPP

#include <SFML/Network.hpp>
#include <map>
#include <string>

class Engine_event
{
public:
    sf::Uint8 type;
    std::map<std::string,std::string> stringData;
    std::map<std::string,sf::Int32> integerData;
};

#endif // ENGINE_EVENT_HPP
