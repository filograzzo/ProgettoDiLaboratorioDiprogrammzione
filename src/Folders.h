//
// Created by Filippo on 06/09/2023.
//

#ifndef PROGETTIDILABORATORIODIPROGRAMMAZIONE_FOLDERS_H
#define PROGETTIDILABORATORIODIPROGRAMMAZIONE_FOLDERS_H


#include <string>
#include <vector>
#include "Note.h"
#include <algorithm>

class Folders {
protected:
    std::string name; //nome del folder
    std::vector<Note> notesVector; //vettore di lunghezza variabile

public:

    Folders (std::string name);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getNumberOfNotes() const;

    bool addNote(Note& note);

    bool removeNote (Note& note);

    Note* findNoteWithTitol ( const std::string& titol);

    const std::vector<Note> &getNotesVector() const; //non ha senso ci sia un setter di notevector, è creato una volta sola ed è quello relativo al folder stesso




};


#endif //PROGETTIDILABORATORIODIPROGRAMMAZIONE_FOLDERS_H
