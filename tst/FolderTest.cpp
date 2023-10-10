
#include "FolderFixture.h"

// SETTER E GETTER TITOLO

TEST_F (FolderFixture, getFolderTitleTest ){

    ASSERT_EQ (folder->getName(), "Raccolta di note sui gabbiani" );

}

TEST_F (FolderFixture, setFoldersTitleTest ){

    std::string name = "Una raccolta di note sui gabbiani";
    folder->setName(name);
    ASSERT_EQ (folder->getName(), "Una raccolta di note sui gabbiani" );

}

//  FIND NOTE WITH TITOL TEST

TEST_F (FolderFixture, getNoteWithTitleFolderTest ){ //ho già testato add e remove

    folder->addNote(nota );
    ASSERT_EQ(folder->getNoteFromTitle(nota.getTitle(), nota), true); //il titolo della nota aggiunta è uguale ad esempio

    folder->removeNote(nota );
    ASSERT_EQ (folder->getNoteFromTitle(nota.getTitle(), nota) , false );

}

// ADDNOTE E REMOVENOTE

TEST_F (FolderFixture, addNoteFolderTest ){

    folder->addNote(nota );
    bool found = false;
    found = folder->getNoteFromTitle( nota.getTitle(), nota);
    ASSERT_EQ( found, true );
}

TEST_F(FolderFixture, removeNoteFolderTest){

    folder->addNote(nota); //già controllato sopra come operazione
    folder->removeNote(nota );
    bool found = false;
    found = folder->getNoteFromTitle( nota.getTitle(), nota);
    ASSERT_EQ (found, false);

    //test cancellazione nota bloccata
    folder->addNote(nota);
    nota.setBlocked(true);
    folder->removeNote(nota);
    found = folder->getNoteFromTitle( nota.getTitle(), nota);
    ASSERT_EQ(found, true);
}

// GET NUMBER OF NOTES

TEST_F (FolderFixture, getNumberOfNotesFolderTest ){

    ASSERT_EQ (folder->getSize(), 0 );

    folder->addNote(nota);
    ASSERT_EQ (folder->getSize(), 1 );

    folder->addNote(nota);
    ASSERT_EQ (folder->getSize(), 1 ); //se provi ad aggiungere la stessa nota non dovrebbe poterlo fare

    folder->removeNote(nota);
    ASSERT_EQ (folder->getSize(), 0 );

    folder->removeNote(nota);
    ASSERT_EQ (folder->getSize(), 0 ); //se non la trova non dovrebbe fare nulla

}


//TEST SU MAKE E REMOVE FAVOURITE

TEST_F (FolderFixture, makeAndRemoveFavouriteFolderTest){
    folder->addNote(nota);

    bool done = folder->makeFavourite(nota);
    ASSERT_EQ (done , true);

    done =folder->removeFavourite(nota);
    ASSERT_EQ (done, true);
}


//EDIT DI NOTE DA BLOCCATE

TEST_F(FolderFixture, blockedFolderTest){
    folder->addNote(nota);

    folder->blockNote(nota);
    bool done = folder->makeFavourite(nota);
    ASSERT_EQ(done, false);

    folder->unlockNote(nota);
    folder->makeFavourite(nota);
    nota.setBlocked(true);
    done=folder->removeFavourite(nota);
    ASSERT_EQ(done, false);
}