#include "Network_engine.hpp"
#include "Game.hpp"
#include <iostream>

Network_engine::Network_engine(Game *parent) :
    Engine(parent),
    m_iscConnect(false)
{
}

Network_engine::~Network_engine()
{
    deconnexion();
}

bool Network_engine::isConnect() const
{
    return m_iscConnect;
}

sf::Uint32 Network_engine::getIdMachine() const
{
    return m_idMachine;
}

void Network_engine::frame()
{
    if(m_selector.wait(sf::milliseconds(5)))
    {
        if(m_selector.isReady(m_socketTcp))
        {
            sf::Packet packet;
            m_socketTcp.receive(packet);
            traiterPacket(packet);
        }
    }
}

int Network_engine::connect(const sf::IpAddress &ip, const std::string &user, const std::string &password)
{
    if(m_socketTcp.connect(ip, 53000) != sf::Socket::Done)
    {
        std::cerr << "Impossible de se connecter au serveur" << std::endl;
        m_iscConnect = false;
        return 4;
    }
    else
    {
        sf::Packet reception, envoi;
        std::string chaine;
        sf::Int32 id(-1);

        envoi << user << password;
        m_socketTcp.send(envoi);
        envoi.clear();

        m_socketTcp.receive(reception);
        reception >> id;
        reception.clear();

        if(id == -1)
        {
            std::cerr << "Vous n'etes pas inscrit" << std::endl;
            m_iscConnect = false;
            return 1;
        }
        else if(id == -2)
        {
            std::cerr << "Le mot de passe est incorrect" << std::endl;
            return 2;
        }
        else if(id == -3)
        {
            std::cerr << "Cet utilisateur est deja connecte" << std::endl;
            return 3;
        }
        else
        {
            m_idMachine = id;
            m_iscConnect = true;
            std::cout << "id = " << id << std::endl;
        }
    }
    return 0;
}

void Network_engine::traiterPacket(sf::Packet &packet)
{
    sf::Uint8 type;
    packet >> type;

    sf::Packet envoi;
    sf::Uint8 t;
    switch(type)
    {
    case 120: //demande De Ping
        t = 121; //reponse a ping
        envoi << t;
        m_socketTcp.send(packet);
        break;

    case 121: //reponse a ping
        break;
    }

}

void Network_engine::process_event(Engine_event &e)
{

}

void Network_engine::deconnexion()
{

}
