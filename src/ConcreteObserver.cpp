
#include <iostream>
#include "ConcreteObserver.h"
#include "Subject.h"

void ConcreteObserver::update(  std::string name, int note ) {

    std::cout << "È avvenuto un cambiamento nel Folder " << name << " a cui sei iscritto adesso: adesso le note presenti sono " << note << "." << std::endl;
    
}

void ConcreteObserver::subscribe(Subject &subject) {
    subject.addObserver(this);
    channelsList.push_back(&subject);
}

void ConcreteObserver::unsubscribe(Subject &subject) {
    subject.removeObserver(this);
    for ( auto it = channelsList.begin(); it != channelsList.end(); it ++){
        if (*it == &subject){
            channelsList.erase(it);
        }
    }
}

ConcreteObserver::~ConcreteObserver() {

    if ( channelsList.empty() )
        return;
    for ( auto it = channelsList.begin(); it != channelsList.end(); it++){
        this->unsubscribe(**it);
    }
    channelsList.clear(); // rimuove tutti gli elementi da channelsList

}

