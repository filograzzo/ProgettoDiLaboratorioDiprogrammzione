#include "gtest/gtest.h"
#include "../src/Folders.h"
#include "FoldersFixture.cpp"

// SETTER E GETTER TITOLO

TEST_F ( FoldersFixture, getTitolTest ){

    ASSERT_EQ ( folders->getName(), "Raccolta di note sui gabbiani" );

}

TEST_F ( FoldersFixture, setTitolTest ){

    std::string name = "Una raccolta di note sui gabbiani";
    folders->setName( name );
    ASSERT_EQ ( folders->getName(), "Una raccolta di note sui gabbiani" );

}

// SETTER E GETTER COUNTER

TEST_F ( FoldersFixture, getCounterTest ){

    ASSERT_EQ ( folders->getCounter(), 0 );

}

TEST_F ( FoldersFixture, setCounterTest ){

    folders->setCounter(10);
    ASSERT_EQ ( folders->getCounter(), 10);

}

// ADDNOTE E REMOVENOTE

TEST_F (FoldersFixture, addNoteAndRemoveNoteTest ){

    folders->addNote(nota );
    ASSERT_EQ( (folders->findNoteWithTitol(nota.getTitol()))->getTitol(), "Esempio");

    folders->removeNote(nota );
    ASSERT_EQ ( folders->findNoteWithTitol(nota.getTitol()) , nullptr );

}

// todo FIND NOTE WITH TITOL

TEST_F ( FoldersFixture, findNoteWithTitolTest ){



}

//todo continuare a fare test necessari