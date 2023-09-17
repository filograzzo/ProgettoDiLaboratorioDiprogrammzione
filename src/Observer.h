
#ifndef UNIT_TESTING_ESAME_OBSERVER_H
#define UNIT_TESTING_ESAME_OBSERVER_H


class Observer {

public:
    virtual void update( std::string name, int note )=0;
};
#endif //UNIT_TESTING_ESAME_OBSERVER_H
