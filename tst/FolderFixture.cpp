#include "FolderFixture.h"

void FolderFixture::SetUp()  {
    std::string name = "Raccolta di note sui gabbiani";
    folder = new Folder (name );
    Folder::clearFavouriteNotes();
    Folder::clearBlockedNotes();
}

void FolderFixture::TearDown()  {
    delete folder;
    folder = nullptr;
}



