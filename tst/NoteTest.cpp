#include "gtest/gtest.h"
#include "../src/Note.h"
#include "NoteFixture.cpp"

// SETTER E GETTER TITOLO

TEST_F (NoteFixture, getTitolTest){

    ASSERT_EQ ( nota -> getTitol(), "Pellicano" );
}

TEST_F (NoteFixture, setTitolTest){

nota->setTitol("Nota su un pellicano");
ASSERT_EQ ( nota -> getTitol(), "Nota su un pellicano" );
}

// SETTER E GETTER TESTO

TEST_F (NoteFixture, getTextTest){

    ASSERT_EQ ( nota -> getText(), "C'era un pellicano sulla spiaggia." );
}

TEST_F (NoteFixture, setTextTest){

    nota->setText("Oggi ho visto un pellicano sulla spiaggia che mangiava un pezzo di pane");
    ASSERT_EQ ( nota -> getText(), "Oggi ho visto un pellicano sulla spiaggia che mangiava un pezzo di pane" );
}

// SETTER E GETTER BLOCKED

TEST_F (NoteFixture, isBlockedTest){

    ASSERT_EQ ( nota -> isBlocked(), false );
}

TEST_F (NoteFixture, setBlockedTest){

    nota->setBlocked(true);
    ASSERT_EQ (nota -> isBlocked(), true );
}

// TEST PER VEDERE SE BLOCKED FUNZIONA

TEST_F(NoteFixture, blockedOnSetMethods){ //se blocked è true, setTitol e setText non devono funzionare

    nota->setBlocked(true);

    nota->setTitol("Nota su un pellicano");
    ASSERT_EQ ( nota -> getTitol(), "Pellicano" ); //il titolo non dovrebbe essere cambiato

    nota->setText("Oggi ho visto un pellicano sulla spiaggia che mangiava un pezzo di pane");
    ASSERT_EQ ( nota -> getText(), "C'era un pellicano sulla spiaggia." );

}







