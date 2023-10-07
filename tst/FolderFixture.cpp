#include "FolderFixture.h"

void FolderFixture::SetUp()  {
    std::string name = "Raccolta di note sui gabbiani";
    folder = new Folder (name );
}

void FolderFixture::TearDown()  {
    delete folder;
    folder = nullptr;
}



