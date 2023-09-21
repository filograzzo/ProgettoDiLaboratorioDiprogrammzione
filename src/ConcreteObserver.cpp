
#include <iostream>
#include "ConcreteObserver.h"
#include "Subject.h"

void ConcreteObserver::update(  std::string name, int note ) {

    std::cout << "È avvenuto un cambiamento nel Folder " << name << " a cui sei iscritto adesso: adesso le note presenti sono " << note << "." << std::endl;
    
}

void ConcreteObserver::subscribe(Subject &subject) {
    subject.addObserver(this);
}

void ConcreteObserver::unsubscribe(Subject &subject) {
    subject.removeObserver(this);
}
