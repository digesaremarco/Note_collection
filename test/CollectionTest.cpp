
#include "../Collection.h"
#include "../NoteCounter.h"
#include "../LockedNotes.h"
#include "gtest/gtest.h"


//test insert new note into collection
TEST(Collection, addNote){
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    collection.addNote(note1);
    ASSERT_EQ(1, collection.getSize());  //size value expect to be 1
}

//test remove a note from collection
TEST(Collection, removeNote){
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    collection.addNote(note1);
    ASSERT_EQ(1, collection.getSize());
    collection.removeNote(note1);
    ASSERT_EQ(0, collection.getSize());
}

//test remove a note that isn't in the collection
TEST(Collection, removeNoteInvalid){
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    Note note2("title2", "text2", false);
    collection.addNote(note1);
    collection.removeNote(note2);
    ASSERT_EQ(1,collection.getSize());
}

//test add observer
TEST(Collection, addObserver){
    Collection collection("1", false);
    NoteCounter notecounter(collection);
    LockedNotes lockednote(collection);
    ASSERT_EQ(2, collection.getNumObservers());
}

//test remove observer
TEST(Collection, removeObserver){
    Collection collection("1", false);
    NoteCounter notecounter(collection);
    collection.removeObserver(&notecounter);
    ASSERT_EQ(0, collection.getNumObservers());
}

//test notify observers
TEST(Collection, testObservers){
    Collection collection("1", false);
    NoteCounter notecounter(collection);
    LockedNotes lockednote(collection);
    Note note1("title1", "text1", false);
    Note note2("title2", "text2", false);
    Note note3("title3", "text3", true);
    collection.addNote(note1);
    collection.addNote(note2);
    collection.addNote(note3);
    ASSERT_EQ(3, notecounter.getCounter());
    ASSERT_EQ(1, lockednote.getLockedCounter());
}
