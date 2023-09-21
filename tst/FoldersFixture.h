
#ifndef UNIT_TESTING_ESAME_FOLDERSFIXTURE_H
#define UNIT_TESTING_ESAME_FOLDERSFIXTURE_H

#include "gtest/gtest.h"
#include "../src/Folders.h"
#include "../src/Note.h"

class FoldersFixture : public ::testing::Test {

protected:

    Folders* folders;
    std::string NoteTitol = "Esempio";
    std::string ExampleText = "Testo sempio";
    Note nota =  Note ( NoteTitol, ExampleText );

public:

    void SetUp() override;

    void TearDown() override;

};
#endif //UNIT_TESTING_ESAME_FOLDERSFIXTURE_H
