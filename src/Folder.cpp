#include <iostream>
#include "Folder.h"

std::list<Note> Folder::favouriteNotes;

const std::string &Folder::getName() const {
    return name;
}

void Folder::setName(const std::string &name) {
    Folder::name = name;
}

bool Folder::addNote(const Note &note) {

    auto it = std::find(notesList.begin(), notesList.end(), note); //ritorna l'iteratore che punta alla nota

    if (it != notesList.end()) { //se l'iteratore è diverso dalla fine vuol dire che ha trovato la nota già dentro
        return false; //non si può aggiungere una nota già aggiunta
    }

    notesList.push_back(note); // se non trova nessuno col titolo uguale, aggiunge la nota e ritorna vero

    if (note.isFavourite())
        favouriteNotes.push_back(note);

    return true;
}

bool Folder::removeNote(const Note &note) { //si po
    if (note.isBlocked()) {
        std::cout
                << "Stai cercando di cancellare una nota bloccata. Se desideri cancellarla, prima dovrai procedere a sbloccarla."
                << std::endl;
        return false;
    }

    auto it = std::find(notesList.begin(), notesList.end(), note); //ritorna l'iteratore che punta alla nota

    if (it == notesList.end()) {
        return false; //non c'è la nota, ritorna fallimento
    }

    notesList.remove(note); //rimuove la nota

    return true; //ritorna successo
}


int
Folder::getSize() const { //non passare nulla sotto o uguale a double per riferimento, solo strinnghe e oggetti complicati

    return notesList.size();

}

void Folder::blockNote(const Note &note) {

    auto it = std::find(notesList.begin(), notesList.end(), note);
    (*it).setBlocked(true);

}

void Folder::unlockNote(const Note &note) {

    auto it = std::find(notesList.begin(), notesList.end(), note);

    (*it).setBlocked(false);

}

bool Folder::makeFavourite(Note &note) {

    if (!note.isBlocked()) {
        note.setFavourite(true);
        favouriteNotes.push_back(note);
        return true;
    }
    return false;
}

bool Folder::removeFavourite(const Note &note) {

    if (!note.isBlocked()) {
        auto it = std::find(favouriteNotes.begin(), favouriteNotes.end(), note);
        it->setFavourite(false);
        favouriteNotes.remove(*it);
        return true;
    }
    return false;
}

std::list<std::string> Folder::listFavourites() {
    std::list<std::string> titlesList;
    for (const auto &it: favouriteNotes) {
        titlesList.push_back(it.getTitle());
    }
    return titlesList;
}

int Folder::getFavouriteSize() {
    std::list<std::string> countList = listFavourites();
    return countList.size();

}

//fatto in questo modo perché è semlie da testare e perché in caso di fallimento non c'è ua nota particolare da ritornare
bool Folder::getNoteFromTitle(const std::string &title, Note &nota) const {
    for (const auto &it: notesList)
        if (it.getTitle() == title) {
            nota = it;
            return true;
        }
    return false;
}



//da subject

void Folder::addObserver(Observer *o) {

    auto it = std::find(observerList.begin(), observerList.end(), o); //ritorna l'iteratore che punta all'observer
    if (it == observerList.end()) {
        observerList.push_back(o); // se l'osservatore che sta provando ad iscriversi non è già iscritto lo iscrive
        return;
    }
    std::cout << "L'osservatore che si sta provando ad aggiungere è già presente nella lista degli Osservatori."
              << std::endl; //dice che l'osservatore è già presente

}

void Folder::removeObserver(Observer *o) {

    auto it = std::find(observerList.begin(), observerList.end(), o); //ritorna l'iteratore che punta all'observer
    if (*it == o) {
        observerList.remove(o); // se l'osservatore c'è lo disiscrive
        return;
    }
}

void Folder::notifyObservers() {

    if (observerList.empty())
        return;
    for (auto &it: observerList)
        it->update(*this);
}