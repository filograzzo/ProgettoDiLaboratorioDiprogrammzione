//
// Created by Filippo on 06/09/2023.
//

#include "Folders.h"


const std::string &Folders::getName() const {
    return name;
}

void Folders::setName(const std::string &name) {
    Folders::name = name;
}

int Folders::getNumberOfNotes() const {
    return this->notesVector.size();
}

Folders::Folders(std::string name) {
    this->name = name;
}

bool Folders::addNote(Note& note) {
    for (int i = 0; i < notesVector.size(); i++){
        if (notesVector[i].getTitol() == note.getTitol()){
            return false; //se trova una nota con il titolo uguaele non l'aggiunge e ritorna falso
        }
    }
    notesVector.push_back(note); // se non trova nessuno col titolo uguale, aggiunge la nota e ritorna vero
    counter++;
    return true;
}

bool Folders::removeNote(Note& note) {
    for (auto it = notesVector.begin(); it != notesVector.end(); ++it){
        if (it->getTitol() == note.getTitol()){
            notesVector.erase(it); //se il titolo della nota da cancellare viene trovato allora la nota è cancellata e ritorna vero
            counter--;
            return true;
        }
    }
    return false; //se non trova la nota ritorna falso
}

Note* Folders::findNoteWithTitol ( const std::string& titol ){ //ritorna true se ho trovato la nota con lo stesso nome, falso se non la trovo

    for (auto it = notesVector.begin(); it != notesVector.end(); ++it){
        if (it->getTitol() == titol){
            return &(*it); //prendo prima l'oggetto a cui sta puntando l'iteratore e poi ritorno il suo indirizzo
        }
    }
    return nullptr;
}

int Folders::getCounter() const {
    return counter;
}

void Folders::setCounter(int counter) {
    Folders::counter = counter;
}

const std::vector<Note> &Folders::getNotesVector() const {
    return notesVector;
}

void Folders::setNotesVector(const std::vector<Note> &notesVector) {
    Folders::notesVector = notesVector;
}
