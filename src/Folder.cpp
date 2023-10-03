//
// Created by Filippo on 06/09/2023.
//

#include <iostream>
#include "Folder.h"


Folder::Folder(std::string name) {
    this->name = name;
}

const std::string &Folder::getName() const {
    return name;
}

void Folder::setName(const std::string &name) {
    Folder::name = name;
}


int Folder::getNumberOfNotes() const {
    return this->notesVector.size();
}


bool Folder::addNote(Note& note) {
    for (int i = 0; i < notesVector.size(); i++){
        if (notesVector[i].getTitle() == note.getTitle()){
            return false; //se trova una nota con il titolo uguaele non l'aggiunge e ritorna falso
        }
    }
    notesVector.push_back(note); // se non trova nessuno col titolo uguale, aggiunge la nota e ritorna vero
    return true;
}

bool Folder::removeNote(Note& note) {
    if ( note.isBlocked() ){
        std::cout << "Stai cercando di cancellare una nota bloccata. Se desideri cancellarla, prima dovrai procedere a sbloccarla." << std::endl;
        return false;
    }
    for (auto it = notesVector.begin(); it != notesVector.end(); ++it){
        if (it->getTitle() == note.getTitle()){
            notesVector.erase(it); //se il titolo della nota da cancellare viene trovato allora la nota è cancellata e ritorna vero
            return true;
        }
    }
    return false; //se non trova la nota ritorna falso
}

Note* Folder::findNoteWithTitle (const std::string& title ){ //ritorna true se ho trovato la nota con lo stesso nome, falso se non la trovo

    for (auto it = notesVector.begin(); it != notesVector.end(); ++it){
        if (it->getTitle() == title){
            return &(*it); //prendo prima l'oggetto a cui sta puntando l'iteratore e poi ritorno il suo indirizzo
        }
    }
    return nullptr;
}

const std::vector<Note> &Folder::getNotesVector() const {
    return notesVector;
}

//da subject

void Folder::addObserver(Observer *o) {

    for (auto it = observerList.begin(); it != observerList.end(); it++){
        if ( *it == o ){
            std::cout << "L'osservatore che si sta provando ad aggiungere è già presente nella lista degli Osservatori." << std::endl;
            return;
        }
    }
    observerList.push_back(o); // se l'osservatore che sta provando ad iscriversi non è già iscritto lo iscrive

}

void Folder::removeObserver(Observer *o) {

    for (auto it = observerList.begin(); it != observerList.end(); it++){
        if ( *it == o ){
            observerList.erase(it);
            return;
        }
    }

}

void Folder::notifyObservers( ) {

    if ((this->observerList).empty())
        return;

    std::string name = this->name;
    int noteNumber = this->notesVector.size();

    for (auto it = observerList.begin(); it != observerList.end(); it++){
        (*it)->update( name, noteNumber );
    }

}

