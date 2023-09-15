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

// ADDNOTE E REMOVENOTE

TEST_F (FoldersFixture, addNoteAndRemoveNoteTest ){

    folders->addNote(nota );
    bool found = false;
    for ( const Note& iter : folders->getNotesVector()){
        if ( iter.getTitol() == nota.getTitol() ){
            found = true;
            break;
        }
    }
    ASSERT_EQ( found, true );


}

TEST_F(FoldersFixture, removeNoteTest){

    folders->addNote(nota); //già controllato sopra come operazione
    folders->removeNote(nota );
    bool found = false;
    for ( const Note& iter : folders->getNotesVector()) {
        if (iter.getTitol() == nota.getTitol()) {
            found = true;
            break;
        }
    }

    ASSERT_EQ ( found, false );

}

// GET NUMBER OF NOTES

TEST_F ( FoldersFixture, getNumberOfNotesTest ){

    ASSERT_EQ ( folders->getNumberOfNotes(), 0 );

    folders->addNote(nota);
    ASSERT_EQ ( folders->getNumberOfNotes(), 1 );

    folders->addNote(nota);
    ASSERT_EQ ( folders->getNumberOfNotes(), 1 ); //se provi ad aggiungere la stessa nota non dovrebbe poterlo fare

    folders->removeNote(nota);
    ASSERT_EQ ( folders->getNumberOfNotes(), 0 );

    folders->removeNote(nota);
    ASSERT_EQ ( folders->getNumberOfNotes(), 0 ); //se non la trova non dovrebbe fare nulla

}

//  FIND NOTE WITH TITOL TEST

TEST_F ( FoldersFixture, findNoteWithTitolTest ){ //ho già testato add e remove

    folders->addNote(nota );
    ASSERT_EQ( (folders->findNoteWithTitol(nota.getTitol()))->getTitol(), "Esempio"); //il titolo della nota aggiunta è uguale ad esempio

    folders->removeNote(nota );
    ASSERT_EQ ( folders->findNoteWithTitol(nota.getTitol()) , nullptr );

}

