//#include <gtest/gtest.h>
#include "FavouriteFoldersTest.cpp"
#include "FolderTest.cpp"
#include "NoteTest.cpp"

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
