cmake_minimum_required(VERSION 3.17)
project(Note_collection)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(test)
set(SOURCE_FILES  Note.h Note.cpp Collection.h Collection.cpp
        Observer.h Observer.cpp Subject.h Subject.cpp NoteCounter.h NoteCounter.cpp
        LockedNotes.h LockedNotes.cpp AllCollection.h AllCollection.cpp CollectionCounter.h
        CollectionCounter.cpp ImportantCollectionCounter.h ImportantCollectionCounter.cpp)
add_executable(Note_collection main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Note_collection core)