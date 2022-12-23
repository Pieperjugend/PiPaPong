#include <iostream>
#include <vector>
#include <SFML/Network.hpp>

int matchserv()
{
    // Port, auf dem der Server horchen soll
    constexpr unsigned short PORT = 55002;

    // Socket erstellen und an Port binden
    sf::TcpListener listener;
    if (listener.listen(PORT) != sf::Socket::Done) {
        std::cerr << "Fehler beim Erstellen des Serversockets\n";
        return 1;
    }

    // Vector für Client-Verbindungen und -Positionen erstellen
    std::vector<sf::TcpSocket*> clients;
    std::vector<std::pair<int, int>> positions;

    // Hauptschleife des Servers
    while (true) {
        // Client-Verbindungen akzeptieren
        sf::TcpSocket* client = new sf::TcpSocket;
        if (listener.accept(*client) == sf::Socket::Done) {
            // Client-Verbindung wurde hergestellt
            std::cout << "Client verbunden: " << client->getRemoteAddress() << '\n';

            // Client-Verbindung und -Position hinzufügen
            clients.push_back(client);
            positions.emplace_back(0, 0);
        }

        // Nachrichten von Clients empfangen und verarbeiten
        for (size_t i = 0; i < clients.size(); ++i) {
            sf::TcpSocket* client = clients[i];
            std::pair<int, int>& position = positions[i];

            sf::Packet packet;
            if (client->receive(packet) == sf::Socket::Done) {
                // Nachricht empfangen, verarbeiten
                std::string message;
                packet >> message;

                if (message == "sync") {
                    // Synchronisationsnachricht empfangen, Positionsdaten des Clients aktualisieren
                    packet >> position.first >> position.second;
                }
                else {
                    // Andere Nachricht empfangen, an alle anderen Clients weiterleiten
                    for (size_t j = 0; j < clients.size(); ++j) {
                        if (i != j) {
                            clients[j]->send(packet);
                        }
                    }
                }
            }
            else if (client->getRemoteAddress() == sf::IpAddress::None) {
                // Client hat sich getrennt, Verbindung entfernen
                delete client;
            }
        }
    }

    return 0;
}