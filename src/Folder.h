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
    std::list<Note> notesList; //vettore di lunghezza variabile



public:

    explicit Folder (const std::string& name): name(name){};

    virtual ~Folder() = default; //la libreria <vector> distrugge da sola gli elementi al proprio interno quando va fuori scopo

    const std::string &getName() const;

    void setName(const std::string &name);

    int getNumberOfNotes() const;

    bool addNote(const Note& note);

    bool removeNote (const Note& note); //rif costante

    const int &getSize() const ;

    void blockNote (const Note& note);

    void unlockNote ( const Note & note);

    //da subject

    void addObserver(Observer *o) override; //non virtual perché c'è override
    void removeObserver (Observer *o) override;
    void notifyObservers(  ) override;




};


#endif //PROGETTIDILABORATORIODIPROGRAMMAZIONE_FOLDERS_H
