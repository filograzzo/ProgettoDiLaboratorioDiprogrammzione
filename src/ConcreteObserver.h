
#ifndef UNIT_TESTING_ESAME_CONCRETEOBSERVER_H
#define UNIT_TESTING_ESAME_CONCRETEOBSERVER_H


#include "Observer.h"
#include <vector>

class Subject; //forward declaration

class ConcreteObserver : public Observer {
protected:
    std::string name;
    std::vector<Subject*> channelsList; //lista di puntatori ai cnali a cui l'observer è abbonato

public:
    explicit ConcreteObserver(const std::string& n) : name(n) {}

    ~ConcreteObserver() override; //se il ConcreteObject è iscritto a qualche cnale lo disiscrive, altrimenti non fa nulla

    virtual void update(  std::string name, int note ) override; //dico quante note sono presenti all'interno del folder
    virtual void subscribe(Subject& subject);
    virtual void unsubscribe(Subject& subject);
};


#endif //UNIT_TESTING_ESAME_CONCRETEOBSERVER_H
