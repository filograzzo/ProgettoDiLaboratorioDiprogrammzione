
#ifndef UNIT_TESTING_ESAME_OBSERVER_H
#define UNIT_TESTING_ESAME_OBSERVER_H

#include "Folders.h"

class Observer {

public:
    virtual void update( Folders* f )=0;
};
#endif //UNIT_TESTING_ESAME_OBSERVER_H
