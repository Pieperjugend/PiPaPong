#include <iostream>
#include "queue.h"
#include "matchserv.h"

int main()
{
    // Queue- und MatchServ-Objekte erstellen
    Queue queue;
    MatchServ matchServ;

    // Queue mit MatchServ verbinden
    queue.setMatchServ(&matchServ);
    matchServ.setQueue(&queue);

    // Queue und MatchServ starten
    queue.start();
    matchServ.start();

    // Endlosschleife, um das Programm laufen zu lassen
    while (true) {
        // Optionen für die Verarbeitung von Systemereignissen hier
    }

    return 0;
}
