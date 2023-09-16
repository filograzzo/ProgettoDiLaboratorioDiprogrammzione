//
// Created by Filippo on 16/09/2023.
//

#include <iostream>
#include "ConcreteSubject.h"

void ConcreteSubject::addObserver(Observer *o) {

    for (auto it = observerList.begin(); it != observerList.end(); it++){
        if ( *it == o ){
            std::cout << "L'osservatore che si sta provando ad aggiungere è già presente nella lista degli Osservatori." << std::endl;
            return;
        }
    }
    observerList.push_back(o); // se l'osservatore che sta provando ad iscriversi non è già iscritto lo iscrive

}

void ConcreteSubject::removeObserver(Observer *o) {

    for (auto it = observerList.begin(); it != observerList.end(); it++){
        if ( *it == o ){
            observerList.erase(it);
            return;
        }
    }

    //se l'osservatore che si sta cercando di eliminare non esiste nella lista mando messaggio di "errore"
    std::cout << "L'osservatore che si sta provando a disiscrivere non è presente nella lista degli Osservatori." << std::endl;

}

void ConcreteSubject::notifyObservers( Folders* f ) {

    if ((this->observerList).empty())
        return;

    for (auto it = observerList.begin(); it != observerList.end(); it++){
        (*it)->update( f );
    }

}
