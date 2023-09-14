#include "gtest/gtest.h"
#include "../src/Note.h"
#include "NoteFixture.cpp"

TEST_F (NoteFixture, getTitolTest){

    ASSERT_EQ ( nota -> getTitol(), "Pellicano" );
}

TEST_F (NoteFixture, getTextTest){

    ASSERT_EQ ( nota -> getTitol(), "C'era un pellicano sulla spiaggia." );
}

TEST_F (NoteFixture, isBlockedTest){

    ASSERT_EQ ( nota -> isBlocked(), false );
}

TEST_F (NoteFixture, setBlockedTest){

    nota->setBlocked(true);
    ASSERT_EQ (nota -> isBlocked(), true );
}

TEST_F (NoteFixture, setTitolTest){

    nota->setTitol("Nota su un pellicano");
    ASSERT_EQ ( nota -> getTitol(), "Nota su un pellicano" );
}

TEST_F (NoteFixture, setTextTest){

    nota->setText("Oggi ho visto un pellicano sulla spiaggia che mangiava un pezzo di pane");
    ASSERT_EQ ( nota -> getTitol(), "Oggi ho visto un pellicano sulla spiaggia che mangiava un pezzo di pane" );
}




