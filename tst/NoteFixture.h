

#ifndef UNIT_TESTING_ESAME_NOTEFIXTURE_H
#define UNIT_TESTING_ESAME_NOTEFIXTURE_H

#include "gtest/gtest.h"
#include "../src/Note.h"


class NoteFixture : public ::testing::Test {

protected:

    Note* nota;

public:

    void SetUp() override;

    void TearDown() override;
};


#endif //UNIT_TESTING_ESAME_NOTEFIXTURE_H
