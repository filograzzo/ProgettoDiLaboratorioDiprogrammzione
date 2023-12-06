
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
    ASSERT_TRUE(folder->getNoteFromTitle(nota.getTitle(), nota)); //il titolo della nota aggiunta è uguale ad esempio

    folder->removeNote(nota );
    ASSERT_FALSE(folder->getNoteFromTitle(nota.getTitle(), nota));

}

// ADDNOTE E REMOVENOTE

TEST_F (FolderFixture, addNoteFolderTest ){

    folder->addNote(nota );
    Note newNote = Note("", "");
    ASSERT_TRUE(folder->getNoteFromTitle(nota.getTitle(), newNote));

}

TEST_F(FolderFixture, removeNoteFolderTest){

    folder->addNote(nota); //già controllato sopra come operazione
    ASSERT_EQ ( folder->getSize(), 1);
    folder->removeNote(nota );
    ASSERT_EQ ( folder->getSize(), 0);
    ASSERT_FALSE( folder->getNoteFromTitle( nota.getTitle(), nota));
    ASSERT_FALSE(folder->removeNote(nota ));
    ASSERT_EQ ( folder->getSize(), 0);

    //test cancellazione nota bloccata, ASSERT TRUE, controllare se il numero delle note sia cambiato
    folder->addNote(nota);
    nota.setBlocked(true);
    folder->removeNote(nota);
    ASSERT_TRUE( folder->getNoteFromTitle( nota.getTitle(), nota));
    ASSERT_EQ ( folder->getSize(), 1);
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
    ASSERT_TRUE( folder->makeFavourite(nota));
    ASSERT_EQ (folder->getFavouriteSize(), 1);
    ASSERT_TRUE(folder->removeFavourite(nota));
    ASSERT_EQ (folder->getFavouriteSize(), 0);
}

//EDIT DI NOTE DA BLOCCATE

TEST_F(FolderFixture, blockedFolderTest){
    folder->addNote(nota);
    nota.setBlocked(true);
    ASSERT_FALSE(folder->makeFavourite(nota));
    ASSERT_EQ(folder->getFavouriteSize(), 0);

    nota.setBlocked(true);
    folder->makeFavourite(nota);
    ASSERT_EQ(folder->getFavouriteSize(), 1);
    nota.setBlocked(true);
    ASSERT_FALSE(folder->removeFavourite(nota));
    ASSERT_EQ(folder->getFavouriteSize(), 1);

}