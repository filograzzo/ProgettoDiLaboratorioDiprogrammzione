//
// Created by Filippo on 05/09/2023.
//

#include "Note.h"

Note::Note(std::string &ti, std::string &te) {
    this->titol = ti;
    this->text = te;
}

const std::string &Note::getTitol() const {
    return titol;
}

bool Note::setTitol(const std::string &titol) {
    if (!this->blocked){
        this->titol = titol;
        return true;
    }
    else return false;
}


const std::string &Note::getText() const {
    return text;
}

bool Note::setText(const std::string &text) {
    if (!this->blocked){
        this->text = text;
        return true;
    }
    else return false;
}

bool Note::isBlocked() const {
    return blocked;
}

void Note::setBlocked(bool blocked) {
    Note::blocked = blocked;
}
