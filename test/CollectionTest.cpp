
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

//test show a note that is in the collection
TEST(Collection, showNote){
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    collection.addNote(note1);
    collection.showNote(note1);
    ASSERT_EQ(1,collection.getSize());
}

//test show a note that isn't in the collection
TEST(Collection, showNoteInvalid){
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    Note note2("title2", "text2", false);
    collection.addNote(note1);
    collection.showNote(note2);
    ASSERT_EQ(1,collection.getSize());
}

//test update a note that is in the collection
TEST(Collection, updateNote){
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    collection.addNote(note1);
    collection.updateNote(note1);
    ASSERT_EQ(1,collection.getSize());
}

//test update a note that isn't in the collection
TEST(Collection, updateNoteInvalid){
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    Note note2("title2", "text2", false);
    collection.addNote(note1);
    collection.updateNote(note2);
    ASSERT_EQ(1,collection.getSize());
}