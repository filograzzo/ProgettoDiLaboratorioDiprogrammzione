//
// Created by Filippo on 05/09/2023.
//
#include <string>

#ifndef PROGETTIDILABORATORIODIPROGRAMMAZIONE_NOTE_H
#define PROGETTIDILABORATORIODIPROGRAMMAZIONE_NOTE_H


class Note {
protected:  //attributi protetti, condivisi solo con le classi derivate
    std::string titol; //titolo della nota
    std::string text;  //testo all'interno della nota
    bool blocked = false; //la nota può essere modificata o meno

public:

    Note ( std::string &ti, std::string &te); //costruttore, passo il titolo e il testo. La nota non è bloccata di default.

    const std::string &getTitol() const; //Primo const: il valore ritornato è costante. Secondo const: non modifica lo stato dell'oggetto su cui viene chiamata

    bool setTitol(const std::string &titol); //passaggio per riferimento: opera direttamente sullì'argomento passato. Non fa la copia dei dati (possibilmente troppo lunghi)

    const std::string &getText() const;

    bool setText(const std::string &text);

    bool isBlocked() const;

    void setBlocked(bool blocked);


};


#endif //PROGETTIDILABORATORIODIPROGRAMMAZIONE_NOTE_H