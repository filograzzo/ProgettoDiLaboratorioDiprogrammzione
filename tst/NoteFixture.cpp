#include "NoteFixture.h"


void NoteFixture::SetUp()  {
    std::string title = "Pellicano";
    std::string text = "C'era un pellicano sulla spiaggia.";
    nota = new Note( title , text);
}

void NoteFixture::TearDown()  {
    delete nota; //cancello ciò a cui puntava il puntatore
    nota = nullptr; //cancello il puntatore
}


