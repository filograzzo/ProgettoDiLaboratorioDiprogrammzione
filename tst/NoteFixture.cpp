#include "gtest/gtest.h"
#include "../src/Note.h"

class NoteFixture : public ::testing::Test {
protected:

    Note* nota;

    void SetUp() override {
        std::string titol = "Pellicano";
        std::string text = "C'era un pellicano sulla spiaggia.";
        nota = new Note( titol , text);
    }

    void TearDown() override {
        delete nota; //cancello ciò a cui puntava il puntatore
        nota = nullptr; //cancello il puntatore
    }

};
