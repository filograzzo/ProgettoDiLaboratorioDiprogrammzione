set(BINARY ${cmake_project_name}_tst)

add_executable(${BINARY} FolderFixture.cpp NoteFixture.cpp FolderTest.cpp NoteTest.cpp)

target_link_libraries(${BINARY} PUBLIC ${cmake_project_name}_lib gtest) #${TEST_SOURCES}_lib al posto di cmake_project_name
