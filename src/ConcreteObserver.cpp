
#include <iostream>
#include "ConcreteObserver.h"
#include "Subject.h"
#include "Folder.h"

void ConcreteObserver::update( const Folder& folder ) {

    std::cout << "È avvenuto un cambiamento nel Folder " <<  folder.getName() << " a cui sei iscritto adesso: adesso le note presenti sono " << folder.getSize() << "." << std::endl;
    
}

void ConcreteObserver::subscribe( Subject* subject) {

    (*subject).addObserver(this);
    channelsList.push_back(subject);

}

void ConcreteObserver::unsubscribe(Subject* subject) {

    (*subject).removeObserver(this); //rimuovo dalla lista di observer del folder l'osservatore e al contempo tolgo il soggetto dalla lista di soggetti
    // che ho in concreteobserver

    auto it = std::find(channelsList.begin(), channelsList.end(), subject);

    if (it != channelsList.end()) {
        channelsList.erase(it); // Rimuovi il soggetto dalla lista se trovato
    }

}

ConcreteObserver::~ConcreteObserver() {

    if ( channelsList.empty() )
        return;
    for ( auto it = channelsList.begin(); it != channelsList.end(); it++){
        (*it)->removeObserver(this); //si disiscrive da ogni subject a sui era subscribed
    }

}

