
#include <iostream>
#include "ConcreteObserver.h"

void ConcreteObserver::update(  std::string name, int note ) {

    std::cout << "È avvenuto un cambiamento nel Folder " << name << " a cui sei iscritto adesso: adesso le note presenti sono " << note << "." << std::endl;
    
}
