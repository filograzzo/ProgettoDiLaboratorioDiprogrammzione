#include "Observer.h"

#ifndef UNIT_TESTING_ESAME_SUBJECT_H
#define UNIT_TESTING_ESAME_SUBJECT_H


class Subject {

public:
    virtual ~Subject() = default;

    virtual void addObserver( Observer* o )=0;
    virtual void removeObserver( Observer* o )=0;
    virtual void notifyObservers( )=0;
};


#endif //UNIT_TESTING_ESAME_SUBJECT_H
