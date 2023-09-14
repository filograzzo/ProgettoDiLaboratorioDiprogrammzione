#include "gtest/gtest.h"
#include "../src/Folders.h"
#include "../src/Note.h"


class FoldersFixture : public ::testing::Test {

protected:

    Folders* folders;
    std::string NoteTitol = "Esempio";
    std::string ExampleText = "Testo sempio";
    Note nota =  Note ( NoteTitol, ExampleText );

    void SetUp() override {

        std::string name = "Raccolta di note sui gabbiani";
        folders = new Folders ( name );

    }

    void TearDown() override {

        delete folders;
        folders = nullptr;

    }

};

