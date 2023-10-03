//
// Created by Filippo on 06/09/2023.
//

#include <iostream>
#include "Folder.h"




const std::string &Folder::getName() const {
    return name;
}

void Folder::setName(const std::string &name) {
    Folder::name = name;
}


int Folder::getNumberOfNotes() const {
    return this->notesList.size();
}


bool Folder::addNote(const Note& note) {

    auto it = std::find(notesList.begin(), notesList.end(), note); //ritorna l'iteratore che punta alla nota

    if (it == notesList.end()){
        return false; //non si può aggiungere una nota già aggiunta
    }

    notesList.push_back(note); // se non trova nessuno col titolo uguale, aggiunge la nota e ritorna vero
    return true;
}

bool Folder::removeNote(const Note& note) {
    if ( note.isBlocked() ){
        std::cout << "Stai cercando di cancellare una nota bloccata. Se desideri cancellarla, prima dovrai procedere a sbloccarla." << std::endl;
        return false;
    }

    auto it = std::find(notesList.begin(), notesList.end(), note); //ritorna l'iteratore che punta alla nota

    if (it == notesList.end()){
        return false; //non c'è òa nota, ritorna fallimento
    }

    notesList.remove(note); //rimuove la nota

    return true; //ritorna successo
}
/*
Note* Folder::findNoteWithTitle (const std::string& title ){ //ritorna true se ho trovato la nota con lo stesso nome, falso se non la trovo

    for (auto it = notesList.begin(); it != notesList.end(); ++it){
        if (it->getTitle() == title){
            return &(*it); //prendo prima l'oggetto a cui sta puntando l'iteratore e poi ritorno il suo indirizzo
        }
    }
    return nullptr;
}
 */

//da subject

void Folder::addObserver(Observer *o) {

    auto it = std::find(observerList.begin(), observerList.end(), o); //ritorna l'iteratore che punta all'observer

    if (it == observerList.end()){
        observerList.push_back(o); // se l'osservatore che sta provando ad iscriversi non è già iscritto lo iscrive
        return;
    }

    std::cout << "L'osservatore che si sta provando ad aggiungere è già presente nella lista degli Osservatori." << std::endl; //dice che l'osservatore è già presente

}

void Folder::removeObserver(Observer *o) {

    auto it = std::find(observerList.begin(), observerList.end(), o); //ritorna l'iteratore che punta all'observer

    if (*it == o){
        observerList.remove(o); // se l'osservatore c'è lo disiscrive
        return;
    }

}

void Folder::notifyObservers( ) { //questo andrà cambiato quando cambierò observer

    if (observerList.empty())
        return;

    std::string name = this->name;
    int noteNumber = notesList.size();

    for (auto it = observerList.begin(); it != observerList.end(); it++){
        (*it)->update( name, noteNumber );
    }

}

