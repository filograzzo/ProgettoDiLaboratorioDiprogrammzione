set(BINARY ${cmake_project_name})

set(SOURCES ConcreteObserver.cpp Folder.cpp Note.cpp)

add_executable(${BINARY}_run main.cpp ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})