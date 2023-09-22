
#ifndef PROGETTIDILABORATORIODIPROGRAMMAZIONE_FAVOURITEFOLDERS_H
#define PROGETTIDILABORATORIODIPROGRAMMAZIONE_FAVOURITEFOLDERS_H


#include "Folders.h"

class FavouriteFolders: public Folders{
protected:
    bool favourite = false;
    static int counter;

public:

    explicit FavouriteFolders(const std::string &name);

    ~FavouriteFolders() override = default; //non aggiungo nulla di dinamico

    bool isFavourite() const;

    void setFavourite(bool favourite);

    static int getCounter();

    static void setCounter(int counter);

    //nuovo metodo, stampa i nomi di tutte le note all'interno del folder preferito
    void listFavourite () const;


};


#endif //PROGETTIDILABORATORIODIPROGRAMMAZIONE_FAVOURITEFOLDERS_H
