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
    int counter = 0;

public:

    Folders (std::string name);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getNumberOfNotes() const;

    bool addNote(Note& note);

    bool removeNote (Note& note);

    Note* findNoteWithTitol ( const std::string& titol);

    int getCounter() const;

    void setCounter(int counter);

    const std::vector<Note> &getNotesVector() const;

    void setNotesVector(const std::vector<Note> &notesVector);


};


#endif //PROGETTIDILABORATORIODIPROGRAMMAZIONE_FOLDERS_H
