//
// Created by Filippo on 06/09/2023.
//

#ifndef PROGETTIDILABORATORIODIPROGRAMMAZIONE_FOLDERS_H
#define PROGETTIDILABORATORIODIPROGRAMMAZIONE_FOLDERS_H


#include <string>
#include <list>
#include "Note.h"
#include <algorithm>
#include "Subject.h"

class Folder : public Subject {
private:
    std::list<Observer *> observerList; //lista di osservatori

protected:
    std::string name; //nome del folder
    std::list<Note> notesList; //lista di lunghezza variabile
    static std::list<Note> favouriteNotes; //lista di note preferite
    static std::list<Note> blockedNotes; //lista di note bloccate

public:
    explicit Folder(const std::string &name) : name(name) {};

    ~Folder() override = default; //la libreria <list> distrugge da sola gli elementi al proprio interno quando va fuori scopo
    const std::string &getName() const;

    void setName(const std::string &name);

    bool addNote(const Note &note);

    bool removeNote(const std::string &title);

    int getSize() const;

    void blockNote(const Note &note);

    void unlockNote(const Note &note);

    static bool makeFavourite(Note &note);

    static bool removeFavourite(const std::string &title);

    static void clearBlockedNotes();

    static void clearFavouriteNotes();

    static std::list<std::string> listBlocked();

    static std::list<std::string> listFavourites();

    static int getFavouriteSize();

    static int getBlockedSize();

    bool getNoteFromTitle(const std::string &title, Note &nota) const;

    bool changeTitle(Note &note, const std::string &newTitle);

    bool changeText(Note &note, const std::string &newText);

    //da subject
    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notifyObservers() override;

};


#endif //PROGETTIDILABORATORIODIPROGRAMMAZIONE_FOLDERS_H
