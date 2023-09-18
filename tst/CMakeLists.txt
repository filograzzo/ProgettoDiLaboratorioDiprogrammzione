set(BINARY ${cmake_project_name}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES} )#FoldersFixture.h NoteFixture.h FavouriteFoldersTest.cpp FoldersTest.cpp NoteTest.cpp NoteFixture.cpp FoldersFixture.cpp FavouriteFoldersFixture.cpp)

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${cmake_project_name}_lib gtest ) #${TEST_SOURCES}_lib al posto di cmake_project_name



