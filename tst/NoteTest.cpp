
#include "NoteFixture.h"

// SETTER E GETTER TITOLO

TEST_F (NoteFixture, getNoteTitolTest){

    ASSERT_EQ ( nota -> getTitle(), "Pellicano" );
}

TEST_F (NoteFixture, setNoteTitolTest){

nota->setTitle("Nota su un pellicano");
ASSERT_EQ ( nota -> getTitle(), "Nota su un pellicano" );
}

// SETTER E GETTER TESTO

TEST_F (NoteFixture, getNoteTextTest){

    ASSERT_EQ ( nota -> getText(), "C'era un pellicano sulla spiaggia." );
}

TEST_F (NoteFixture, setNoteTextTest){

    nota->setText("Oggi ho visto un pellicano sulla spiaggia che mangiava un pezzo di pane");
    ASSERT_EQ ( nota -> getText(), "Oggi ho visto un pellicano sulla spiaggia che mangiava un pezzo di pane" );
}

// SETTER E GETTER BLOCKED

TEST_F (NoteFixture, isBlockedNoteTest){

    ASSERT_EQ ( nota -> isBlocked(), false );
}

TEST_F (NoteFixture, setBlockedNoteTest){

    nota->setBlocked(true);
    ASSERT_EQ (nota -> isBlocked(), true );
}

// TEST PER VEDERE SE BLOCKED FUNZIONA

TEST_F(NoteFixture, blockedOnSetMethodsNoteTest){ //se blocked è true, setTitol e setText non devono funzionare

    nota->setBlocked(true);

    nota->setTitle("Nota su un pellicano");
    ASSERT_EQ ( nota -> getTitle(), "Pellicano" ); //il titolo non dovrebbe essere cambiato

    nota->setText("Oggi ho visto un pellicano sulla spiaggia che mangiava un pezzo di pane");
    ASSERT_EQ ( nota -> getText(), "C'era un pellicano sulla spiaggia." );

}







