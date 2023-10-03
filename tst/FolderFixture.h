
#ifndef UNIT_TESTING_ESAME_FOLDERFIXTURE_H
#define UNIT_TESTING_ESAME_FOLDERFIXTURE_H

#include "gtest/gtest.h"
#include "../src/Folder.h"
#include "../src/Note.h"

class FolderFixture : public ::testing::Test {

protected:

    Folder* folders;
    std::string NoteTitol = "Esempio";
    std::string ExampleText = "Testo sempio";
    Note nota =  Note ( NoteTitol, ExampleText );

public:

    void SetUp() override;

    void TearDown() override;

};
#endif //UNIT_TESTING_ESAME_FOLDERFIXTURE_H
