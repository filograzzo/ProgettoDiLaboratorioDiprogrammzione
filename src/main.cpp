// Classi che rappresentano note (es. Bear / Evernote). Ogni nota
// è composta da titolo e testo,
// può essere bloccata per evitarne cancellazione/modifica e fa parte
// di una collezione specificata con nome.
// Può anche far parte di una collezione di note importanti oltre che di
// una collezione specifica.
// Usare Observer per indicare quante note stanno in una collezione.

/*
Consentirei operazioni di modifica di note in un folder ---------> questo si può già fare facendo foldersPointer.findNoteWithTitle ( std::string ) -> noteMethod ( bool );
Faccia un po’ di queste modifiche e poi fissiamo un ricevimento.
 */


#include <iostream>
#include "Note.h"
#include "Folders.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Folders* folder = new Folders( "folder");
    folder->findNoteWithTitle("Nota1")->setBlocked(true);
    return 0;
}

