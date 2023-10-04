
#ifndef UNIT_TESTING_ESAME_OBSERVER_H
#define UNIT_TESTING_ESAME_OBSERVER_H

class Subject; //forward declaration
class Folder;

class Observer {

public:
    virtual void update( const Folder& folder  )=0;

    virtual ~Observer() = default;

};
#endif //UNIT_TESTING_ESAME_OBSERVER_H
