//
// Created by Filippo on 07/09/2023.
//

#ifndef PROGETTIDILABORATORIODIPROGRAMMAZIONE_FAVOURITEFOLDERS_H
#define PROGETTIDILABORATORIODIPROGRAMMAZIONE_FAVOURITEFOLDERS_H


#include "Folders.h"

class FavouriteFolders: public Folders{
protected:
    bool favourite = false;
    static int counter;

public:

    explicit FavouriteFolders(const std::string &name);

    bool isFavourite() const;

    void setFavourite(bool favourite);

    static int getCounter();

    static void setCounter(int counter);


};


#endif //PROGETTIDILABORATORIODIPROGRAMMAZIONE_FAVOURITEFOLDERS_H
