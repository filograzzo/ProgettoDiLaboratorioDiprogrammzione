
#ifndef UNIT_TESTING_ESAME_FAVOURITEFOLDERSFIXTURE_H
#define UNIT_TESTING_ESAME_FAVOURITEFOLDERSFIXTURE_H


#include "gtest/gtest.h"
#include "../src/FavouriteFolders.h"


class FavouriteFoldersFixture : public ::testing::Test {

protected:

    void SetUp () override;
    void TearDown () override;

};


#endif //UNIT_TESTING_ESAME_FAVOURITEFOLDERSFIXTURE_H
