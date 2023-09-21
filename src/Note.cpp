//
// Created by Filippo on 05/09/2023.
//

#include "Note.h"

Note::Note(std::string &ti, std::string &te) {
    this->title = ti;
    this->text = te;
}

const std::string &Note::getTitle() const {
    return title;
}

bool Note::setTitle(const std::string &title) {
    if (!this->blocked){
        this->title = title;
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
