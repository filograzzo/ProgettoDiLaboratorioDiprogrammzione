//
// Created by Filippo on 16/09/2023.
//

#ifndef UNIT_TESTING_ESAME_CONCRETEOBSERVER_H
#define UNIT_TESTING_ESAME_CONCRETEOBSERVER_H


#include "Observer.h"

class ConcreteObserver : public Observer {

public:
    virtual void update( Folders * f) override; //dico quante note sono presenti all'interno del folder
};


#endif //UNIT_TESTING_ESAME_CONCRETEOBSERVER_H
