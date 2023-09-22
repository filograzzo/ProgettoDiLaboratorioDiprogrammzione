// Classi che rappresentano note (es. Bear / Evernote). Ogni nota
// è composta da titolo e testo,
// può essere bloccata per evitarne cancellazione/modifica e fa parte
// di una collezione specificata con nome.
// Può anche far parte di una collezione di note importanti oltre che di
// una collezione specifica.
// Usare Observer per indicare quante note stanno in una collezione.

/*
Se una nota è bloccata non deve essere cancellabile nel folder
        Consentirei operazioni di modifica di note in un folder
Un osservatore concreto deve abbonarsi/disabbonarsi (nel distruttore).
Faccia un po’ di queste modifiche e poi fissiamo un ricevimento.
 */


#include <iostream>
#include "Note.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

