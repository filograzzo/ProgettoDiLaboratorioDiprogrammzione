
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

//  FIND NOTE WITH TITLE TEST

TEST_F (FolderFixture, getNoteWithTitleFolderTest ){ //ho già testato add e remove

    folder->addNote(nota );
    ASSERT_TRUE(folder->getNoteFromTitle(nota.getTitle(), nota)); //il titolo della nota aggiunta è uguale ad esempio

    folder->removeNote(nota.getTitle() );
    ASSERT_FALSE(folder->getNoteFromTitle(nota.getTitle(), nota));

}

// ADDNOTE E REMOVENOTE

TEST_F (FolderFixture, addNoteFolderTest ){

    ASSERT_EQ ( folder->getSize(), 0);
    folder->addNote(nota );
    ASSERT_EQ ( folder->getSize(), 1);
    Note newNote = Note("", "");
    ASSERT_TRUE(folder->getNoteFromTitle(nota.getTitle(), newNote));
    folder->changeTitle(newNote, "newNote");
    folder->changeText(newNote, "newText");
    folder->addNote(newNote);
    ASSERT_EQ(folder->getSize(), 2);

}

TEST_F(FolderFixture, removeNoteFolderTest){

    folder->addNote(nota); //già controllato sopra come operazione
    ASSERT_EQ ( folder->getSize(), 1);
    folder->removeNote(nota.getTitle() );
    ASSERT_EQ ( folder->getSize(), 0);
    ASSERT_FALSE( folder->getNoteFromTitle( nota.getTitle(), nota));
    ASSERT_FALSE(folder->removeNote(nota.getTitle() ));
    ASSERT_EQ ( folder->getSize(), 0);

    //test cancellazione nota bloccata, ASSERT TRUE, controllare se il numero delle note sia cambiato
    folder->addNote(nota);
    folder->blockNote(nota);
    ASSERT_FALSE(folder->removeNote(nota.getTitle()));
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

    folder->removeNote(nota.getTitle());
    ASSERT_EQ (folder->getSize(), 0 );

    folder->removeNote(nota.getTitle());
    ASSERT_EQ (folder->getSize(), 0 ); //se non la trova non dovrebbe fare nulla

}

//TEST SU MAKE E REMOVE FAVOURITE

TEST_F (FolderFixture, makeAndRemoveFavouriteFolderTest){
    folder->addNote(nota);
    ASSERT_TRUE( folder->makeFavourite(nota));
    ASSERT_EQ (folder->getFavouriteSize(), 1);
    ASSERT_TRUE(folder->removeFavourite(nota.getTitle()));
    ASSERT_EQ (folder->getFavouriteSize(), 0);
}

//EDIT DI NOTE DA BLOCCATE

TEST_F(FolderFixture, blockedFolderTest){
    folder->addNote(nota);
    nota.setBlocked(true);
    ASSERT_FALSE(folder->makeFavourite(nota));
    ASSERT_EQ(folder->getFavouriteSize(), 0);

    nota.setBlocked(false);
    folder->makeFavourite(nota);
    ASSERT_EQ(folder->getFavouriteSize(), 1);

}

//TEST PER GET_BLOCKED_SIZE

TEST_F(FolderFixture, blockedSizeTest){

    folder->addNote(nota);
    ASSERT_EQ(folder->getBlockedSize(), 0);
    folder->blockNote(nota);
    ASSERT_EQ(folder->getBlockedSize(), 1);
    Folder::clearBlockedNotes();
    ASSERT_EQ(folder->getBlockedSize(), 0);

}

TEST_F(FolderFixture, changeTitleTest){

    folder->addNote(nota);
    ASSERT_EQ(nota.getTitle(), "Esempio");
    ASSERT_TRUE(folder->changeTitle(nota, "Esempio 2"));

}

TEST_F(FolderFixture, changeTextTest){

    folder->addNote(nota);
    ASSERT_EQ(nota.getText(), "Testo esempio");
    folder->changeText(nota, "Testo esempio 2");

}