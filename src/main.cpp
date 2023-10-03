// Classi che rappresentano note (es. Bear / Evernote). Ogni nota
// è composta da titolo e testo,
// può essere bloccata per evitarne cancellazione/modifica e fa parte
// di una collezione specificata con nome.
// Può anche far parte di una collezione di note importanti oltre che di
// una collezione specifica.
// Usare Observer per indicare quante note stanno in una collezione.

/*
 * Fare le liste di inizializzazione per il costruttore.
 * Passare per riferimento costante ciò che può essere passato per riferimento costante.
 * Refactor di Folder in Folder
 * Togliere getNotesVector (distrugge incapsulamento)
 * In folders fare un metodo per bloccare/sbloccare una nota
 * Togliere findNoteWithTitol
 * Mettere la forward declaration da ConcreteObserver in Observer
 * A subscribe e unsubscribe va passato l'indirizzo di subject
 * CAMBIARE I VETTORI IN LISTE: PER CERCARE C'è UN METODO FIND() CHE è MOLTO PIù VELOCE DI FARE I CICLI
 * Nel distruttore ConcreteObserver chiamare il metodo subject.removeObserver
 * Togliere FavouriteFolders e unirlo a Folder
 */


#include <iostream>
#include "Note.h"
#include "Folder.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Folder* folder = new Folder("folder");
    folder->findNoteWithTitle("Nota1")->setBlocked(true);
    return 0;
}

