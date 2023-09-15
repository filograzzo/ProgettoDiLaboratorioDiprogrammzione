//
// Created by Filippo on 07/09/2023.
//

#include "FavouriteFolders.h"

FavouriteFolders::FavouriteFolders(const std::string &name) : Folders(name) {}

bool FavouriteFolders::isFavourite() const {
    return favourite;
}

void FavouriteFolders::setFavourite(bool favourite) {
    FavouriteFolders::favourite = favourite;
    if ( favourite == false )
        counter --;
    else counter ++;
}

int FavouriteFolders::getCounter() {
    return counter;
}

void FavouriteFolders::setCounter(int counter) {
    FavouriteFolders::counter = counter;
}
