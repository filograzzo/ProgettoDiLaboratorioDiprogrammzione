//
// Created by Filippo on 16/09/2023.
//

#ifndef UNIT_TESTING_ESAME_CONCRETEOBSERVER_H
#define UNIT_TESTING_ESAME_CONCRETEOBSERVER_H


#include "Observer.h"
class Subject; //forward declaration ??

class ConcreteObserver : public Observer {

public:
    virtual void update(  std::string name, int note ) override; //dico quante note sono presenti all'interno del folder
    virtual void subscribe(Subject& subject);
    virtual void unsubscribe(Subject& subject);
};


#endif //UNIT_TESTING_ESAME_CONCRETEOBSERVER_H
