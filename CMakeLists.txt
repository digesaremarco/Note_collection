cmake_minimum_required(VERSION 3.24)
project(Note_collection)

set(CMAKE_CXX_STANDARD 17)

add_executable(Note_collection main.cpp Note.h Note.cpp Collection.h Collection.cpp Observer.h Observer.cpp Subject.h Subject.cpp NoteCounter.h NoteCounter.cpp LockedNotes.h LockedNotes.cpp AllCollection.h AllCollection.cpp)
