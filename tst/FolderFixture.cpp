#include "FolderFixture.h"


void FolderFixture::SetUp()  {

    std::string name = "Raccolta di note sui gabbiani";
    folders = new Folder (name );

}

void FolderFixture::TearDown()  {

    delete folders;
    folders = nullptr;

}



