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
    return false;
}


const std::string &Note::getText() const {
    return text;
}

bool Note::setText(const std::string &text) {
    if (!this->blocked){
        this->text = text;
        return true;
    }
    return false;
}

bool Note::isBlocked() const {
    return blocked;
}

void Note::setBlocked(bool blocked) {
    this->blocked = blocked;
}

bool Note::isFavourite() const {
    return favourite;
}

void Note::setFavourite(bool favourite) {
    this->favourite = favourite;
}

bool Note::operator==(const Note &other) const {
    if ( this->title == other.title && this->text == other.text )
        return true;
    return false;
}
