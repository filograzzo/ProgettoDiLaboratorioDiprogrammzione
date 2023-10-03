//
// Created by Filippo on 06/09/2023.
//

#ifndef PROGETTIDILABORATORIODIPROGRAMMAZIONE_FOLDERS_H
#define PROGETTIDILABORATORIODIPROGRAMMAZIONE_FOLDERS_H


#include <string>
#include <vector>
#include "Note.h"
#include <algorithm>
#include "Subject.h"

class Folder : public Subject{
private:
    std::vector<Observer*> observerList; //lista di osservatori
    
protected:
    std::string name; //nome del folder
    std::vector<Note> notesVector; //vettore di lunghezza variabile



public:

    explicit Folder (const std::string& name): name(name){};

    virtual ~Folder() = default; //la libreria <vector> distrugge da sola gli elementi al proprio interno quando va fuori scopo

    const std::string &getName() const;

    void setName(const std::string &name);

    int getNumberOfNotes() const;

    bool addNote(const Note& note);

    bool removeNote (const Note& note); //rif costante

    Note* findNoteWithTitle ( const std::string& title);

    //const std::vector<Note> &getNotesVector() const; //non ha senso ci sia un setter di notevector, è creato una volta sola ed è quello relativo al folder stesso

    //da subject

    void addObserver(Observer *o) override; //non virtual perché c'è override
    void removeObserver (Observer *o) override;
    void notifyObservers(  ) override;




};


#endif //PROGETTIDILABORATORIODIPROGRAMMAZIONE_FOLDERS_H
