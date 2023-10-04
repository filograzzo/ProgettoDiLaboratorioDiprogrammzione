//
// Created by Filippo on 05/09/2023.
//

#include "Note.h"


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

bool Note::isFavourite() const {
    return favourite;
}

void Note::setFavourite(bool favourite) {
    Note::favourite = favourite;
}
