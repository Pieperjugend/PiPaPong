#include <iostream>
#include <queue>
#include <SFML/Network.hpp>

int main()
{
    // Port, auf dem der Server horchen soll
    constexpr unsigned short PORT = 55001;

    // Socket erstellen und an Port binden
    sf::TcpListener listener;
    if (listener.listen(PORT) != sf::Socket::Done) {
        std::cerr << "Fehler beim Erstellen des Serversockets\n";
        return 1;
    }

    // Warteschlange für Clients erstellen
    std::queue<sf::TcpSocket*> clientQueue;

    // Hauptschleife des Servers
    while (true) {
        // Client-Verbindungen akzeptieren
        sf::TcpSocket* client = new sf::TcpSocket;
        if (listener.accept(*client) == sf::Socket::Done) {
            // Client-Verbindung wurde hergestellt
            std::cout << "Client verbunden: " << client->getRemoteAddress() << '\n';

            // Client in Warteschlange einfügen
            clientQueue.push(client);

            // Prüfen, ob genügend Spieler für ein Match vorhanden sind
            if (clientQueue.size() >= 2) {
                // Match starten
                std::cout << "Match startet...\n";

                // Nachricht an alle Spieler senden
                sf::Packet packet;
                packet << "Match startet...\n";
                for (int i = 0; i < 4; i++) {
                    sf::TcpSocket* player = clientQueue.front();
                    clientQueue.pop();
                    player->send(packet);
                    delete player;
                }
            }
            else {
                // Nachricht an Client senden, dass er in der Warteschlange ist
                sf::Packet packet;
                packet << "Du bist in der Warteschlange für das nächste Match...\n";
                client->send(packet);
            }
        }
    }

    return 0;
}
