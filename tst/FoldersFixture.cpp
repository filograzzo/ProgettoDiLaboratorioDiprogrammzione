#include "FoldersFixture.h"


void FoldersFixture::SetUp()  {

    std::string name = "Raccolta di note sui gabbiani";
    folders = new Folders ( name );

}

void FoldersFixture::TearDown()  {

    delete folders;
    folders = nullptr;

}



