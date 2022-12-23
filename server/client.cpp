#include <iostream>
#include <SFML/Network.hpp>

int main()
{
    // Server-IP und -Port
    sf::IpAddress serverIp = "127.0.0.1";
    unsigned short serverPort = 55001;

    // Socket für Client erstellen
    sf::TcpSocket clientSocket;

    // Verbindung zum Server herstellen
    if (clientSocket.connect(serverIp, serverPort) != sf::Socket::Done) {
        std::cerr << "Fehler beim Herstellen der Verbindung zum Server\n";
        return 1;
    }

    // Hauptschleife des Clients
    while (true) {
        // Benutzer-Eingabe abfragen
        std::cout << "Nachricht eingeben: ";
        std::string message;
        std::getline(std::cin, message);

        // Nachricht an Server senden
        sf::Packet packet;
        packet << message;
        if (clientSocket.send(packet) != sf::Socket::Done) {
            std::cerr << "Fehler beim Senden der Nachricht\n";
            return 1;
        }

        // Antwort vom Server empfangen
        if (clientSocket.receive(packet) == sf::Socket::Done) {
            std::string response;
            packet >> response;
            std::cout << "Antwort vom Server: " << response << '\n';
        }
        else {
            std::cerr << "Fehler beim Empfangen der Antwort\n";
            return 1;
        }
    }

    // Verbindung schließen
    clientSocket.disconnect();

    return 0;
}