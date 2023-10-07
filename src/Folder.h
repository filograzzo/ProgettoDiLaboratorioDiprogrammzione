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

class Folder : public Subject{
private:
    std::list<Observer*> observerList; //lista di osservatori
    
protected:
    std::string name; //nome del folder
    std::list<Note> notesList; //lista di lunghezza variabile
    static std::list<Note> favouriteNotes; //lista di note preferite

public:
    explicit Folder (const std::string& name): name(name){};
    virtual ~Folder() = default; //la libreria <list> distrugge da sola gli elementi al proprio interno quando va fuori scopo
    const std::string &getName() const;
    void setName(const std::string &name);
    bool addNote(const Note& note);
    bool removeNote (const Note& note);
    const int &getSize() const ;
    void blockNote (const Note& note);
    void unlockNote ( const Note & note);
    bool makeFavourite ( Note & note );
    bool removeFavourite ( const Note & note );
    std::list <std::string> listFavourites () const;
    bool getNoteFromTitle (const std::string &title, Note &nota) const;

    //da subject
    void addObserver(Observer *o) override;
    void removeObserver (Observer *o) override;
    void notifyObservers(  ) override;




};


#endif //PROGETTIDILABORATORIODIPROGRAMMAZIONE_FOLDERS_H
