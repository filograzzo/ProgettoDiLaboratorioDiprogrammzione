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

    if(note.isBlocked())
        blockedNotes.push_back(note);

    notifyObservers();

    return true;
}

bool Folder::removeNote(const std::string &title) {

    for (auto it : notesList) {
        if (it.getTitle() == title) {
            if (it.isBlocked()) {
                std::cout
                        << "Stai cercando di cancellare una nota bloccata. Se desideri cancellarla, prima dovrai procedere a sbloccarla."
                        << std::endl;
                return false;
            }
            notesList.remove(it);
            favouriteNotes.remove(it);
            notifyObservers();
            return true;
        }
    }
    return false; //se la nota non viene trovata

}


int Folder::getSize() const { //non passare nulla sotto o uguale a double per riferimento, solo strinnghe e oggetti complicati

    return notesList.size();

}

void Folder::blockNote(const Note &note) {
    auto it = std::find(notesList.begin(), notesList.end(), note);

    if (it != notesList.end()) {
        it->setBlocked(true);
        blockedNotes.push_back(*it);
    } else {
        std::cout << "Nota non trovata nella lista." << std::endl;
    }
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

bool Folder::removeFavourite(const std::string &title) {


    auto it = std::find_if(favouriteNotes.begin(), favouriteNotes.end(), [&](const Note& n){ return n.getTitle()==title; });

    if(it!=favouriteNotes.end() && !it->isBlocked()) {
        favouriteNotes.erase(it);
        return true; //se la nota non viene trovata
    }

    if (it!=favouriteNotes.end() && it->isBlocked()) {
        std::cout
                << "Stai cercando di cancellare dai preferiti una nota bloccata. Se desideri proseguire, prima dovrai procedere a sbloccarla."
                << std::endl;
        return false;
    }

    return false;
}
/*
    if (!note.isBlocked()) {
        auto it = std::find(favouriteNotes.begin(), favouriteNotes.end(), note);
        it->setFavourite(false);
        favouriteNotes.remove(*it);
        return true;
    }
    return false;*/


void Folder::clearBlockedNotes() {
    Folder::blockedNotes.clear();
}

void Folder::clearFavouriteNotes() {
    Folder::favouriteNotes.clear();
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
    return blockedNotes.size();
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

bool Folder::changeTitle( Note &note, const std::string &newTitle) {
        auto it = std::find(notesList.begin(), notesList.end(), note);
        if (it != notesList.end()){
            bool done = (*it).setTitle(newTitle);
            notifyObservers();
            return done;
        }
    return false; //può ritornare false in due casi: la nota è bloccata (lo ritornerà setTitle) o se non trova la nota nella lista
}

bool Folder::changeText( Note &note, const std::string &newText) {
    auto it = std::find(notesList.begin(), notesList.end(), note);
    if (it != notesList.end()){
        bool done = (*it).setText(newText);
        notifyObservers();
        return done;
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


