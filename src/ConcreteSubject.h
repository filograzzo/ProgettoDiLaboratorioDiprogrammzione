//
// Created by Filippo on 16/09/2023.
//

#ifndef UNIT_TESTING_ESAME_CONCRETESUBJECT_H
#define UNIT_TESTING_ESAME_CONCRETESUBJECT_H


#include "Subject.h"
#include <vector>

class ConcreteSubject : public Subject {
private:
    static std::vector<Observer*> observerList;

public:
     void addObserver(Observer *o) override;
     void removeObserver (Observer *o) override;
     void notifyObservers( Folders* f ) override;


};


#endif //UNIT_TESTING_ESAME_CONCRETESUBJECT_H
