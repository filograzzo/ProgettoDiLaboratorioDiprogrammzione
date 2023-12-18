#include <iostream>
#include "Folder.h"

std::list<Note> Folder::favouriteNotes;
std::list<Note> Folder::blockedNotes;

const std::string &Folder::getName() const {
    return name;
}

void Folder::setName(const std::string &name) {
    Folder::name = name;
    notifyObservers();
}

bool Folder::addNote(const Note &note) {

    auto it = std::find(notesList.begin(), notesList.end(), note); //ritorna l'iteratore che punta alla nota

    if (it != notesList.end()) { //se l'iteratore è diverso dalla fine vuol dire che ha trovato la nota già dentro
        return false; //non si può aggiungere una nota già aggiunta
    }

    notesList.push_back(note); // se non trova nessuno col titolo uguale, aggiunge la nota e ritorna vero

    if (note.isFavourite())
        favouriteNotes.push_back(note);

    notifyObservers();

    return true;
}

bool Folder::removeNote(const Note &note) { //si può cancellare la nota solo sulla base del titolo
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

    notifyObservers();

    return true; //ritorna successo
}


int
Folder::getSize() const { //non passare nulla sotto o uguale a double per riferimento, solo strinnghe e oggetti complicati

    return notesList.size();

}

void Folder::blockNote(const Note &note) {

    auto it = std::find(notesList.begin(), notesList.end(), note);
    (*it).setBlocked(true);
    blockedNotes.push_back(note);

}

void Folder::unlockNote(const Note &note) {

    auto it = std::find(notesList.begin(), notesList.end(), note);
    (*it).setBlocked(false);
    blockedNotes.remove(note);
}

bool Folder::makeFavourite(Note &note) {

    bool done = note.setFavourite(true);
    if(done){
        favouriteNotes.push_back(note);
    }
    return done;

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

std::list<std::string> Folder::listBlocked() {
    std::list<std::string> titlesList;
    for (const auto &it: blockedNotes) {
        titlesList.push_back(it.getTitle());
    }
    return titlesList;
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

int Folder::getBlockedSize() {
    std::list<std::string> countList = listBlocked();
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

bool Folder::changeTitle(const Note &note, std::string newTitle) {
        auto it = std::find(notesList.begin(), notesList.end(), note);
        if (it != notesList.end()){
            return (*it).setTitle(newTitle);
            notifyObservers();
        }
    return false; //può ritornare false in due casi: la nota è bloccata (lo ritornerà setTitle) o se non trova la nota nella lista
}

bool Folder::changeText(const Note &note, std::string newText) {
    auto it = std::find(notesList.begin(), notesList.end(), note);
    if (it != notesList.end()){
        return (*it).setText(newText);
        notifyObservers();
    }
    return false; //può ritornare false in due casi: la nota è bloccata (lo ritornerà setText) o se non trova la nota nella lista
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


