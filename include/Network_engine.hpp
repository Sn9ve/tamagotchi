#ifndef NETWORK_ENGINE_HPP
#define NETWORK_ENGINE_HPP

#include "Engine.hpp"
#include <SFML/Network.hpp>
#include <memory>

class Network_engine : public Engine
{
public:
    Network_engine(Game *parent);
    virtual ~Network_engine();
    bool isConnect() const;
    sf::Uint32 getIdMachine() const;
    virtual void frame();
    int connect(const sf::IpAddress &ip, const std::string &user, const std::string &password);
    void traiterPacket(sf::Packet &packet);
protected:
    bool m_iscConnect;
    sf::Uint32 m_idMachine;
    sf::TcpSocket m_socketTcp;
    sf::SocketSelector m_selector;
    virtual void process_event(Engine_event &e);
    void deconnexion();
};

#endif // NETWORK_ENGINE_HPP
