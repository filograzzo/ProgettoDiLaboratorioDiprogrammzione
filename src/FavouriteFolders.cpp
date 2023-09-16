
#include <iostream>
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

void FavouriteFolders::listFavourite() const {

    std::cout << "La lista " << this->name << " messa tra i Folder preferiti contine le note: " << std::endl;
    for ( Note it : notesVector ){
        std::cout << " - " << it.getTitol()  << " ;" << std::endl;
    }

}
