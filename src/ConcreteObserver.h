
#ifndef UNIT_TESTING_ESAME_CONCRETEOBSERVER_H
#define UNIT_TESTING_ESAME_CONCRETEOBSERVER_H


#include "Observer.h"
#include <list>
#include <algorithm>



class ConcreteObserver : public Observer {
protected:
    std::string name;
    std::list<Subject*> channelsList; //lista di puntatori ai canali a cui l'observer è abbonato

public:
    explicit ConcreteObserver(const std::string& n) : name(n) {}

    ~ConcreteObserver() override; //se il ConcreteObject è iscritto a qualche cnale lo disiscrive, altrimenti non fa nulla

    void update ( const Folder& folder ) override; //dico quante note sono presenti all'interno del folder
    virtual void subscribe( Subject* subject);
    virtual void unsubscribe(Subject* subject);
};


#endif //UNIT_TESTING_ESAME_CONCRETEOBSERVER_H
