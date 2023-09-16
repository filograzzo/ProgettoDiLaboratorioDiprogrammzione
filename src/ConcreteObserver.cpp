
#include <iostream>
#include "ConcreteObserver.h"

void ConcreteObserver::update( Folders* f ) {

    std::cout << "All'interno del folder ' " << f->getName() << " ' sono presenti " << f->getNumberOfNotes() << " note." << std::endl;
    
}
