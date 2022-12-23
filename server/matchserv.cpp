#include <iostream>
#include <vector>
#include <SFML/Network.hpp>

int main()
{
    // Port, auf dem der Server horchen soll
    constexpr unsigned short PORT = 55002;

    // Socket erstellen und an Port binden
    sf::TcpListener listener;
    if (listener.listen(PORT) != sf::Socket::Done) {
        std::cerr << "Fehler beim Erstellen des Serversockets\n";
        return 1;
    }

    // Vector für Client-Verbindungen erstellen
    std::vector<sf::TcpSocket*> clients;

    // Hauptschleife des Servers
    while (true) {
        // Client-Verbindungen akzeptieren
        sf::TcpSocket* client = new sf::TcpSocket;
        if (listener.accept(*client) == sf::Socket::Done) {
            // Client-Verbindung wurde hergestellt
            std::cout << "MatchServ - Client verbunden: " << client->getRemoteAddress() << '\n';

            // Client-Verbindung hinzufügen
            clients.push_back(client);
        }

        // Nachrichten von Clients empfangen und an alle anderen Clients weiterleiten
        for (auto it = clients.begin(); it != clients.end(); ) {
            sf::TcpSocket* client = *it;

            sf::Packet packet;
            if (client->receive(packet) == sf::Socket::Done) {
                // Nachricht empfangen, an alle anderen Clients weiterleiten
                for (auto it2 = clients.begin(); it2 != clients.end(); ++it2) {
                    if (it2 != it) {
                        (*it2)->send(packet);
                    }
                }
            }
            else if (client->getRemoteAddress() == sf::IpAddress::None) {
                // Client hat sich getrennt, Verbindung entfernen
                delete client;
                it = clients.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    return 0;
}