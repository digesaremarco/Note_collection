
#include "../Collection.h"
#include "../NoteCounter.h"
#include "../LockedNotesCounter.h"
#include "gtest/gtest.h"


//test insert new note into collection
TEST(Collection, addNote) {
    std::cout << "add note" << std::endl;
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    collection.addNote(note1);
    ASSERT_EQ(1, collection.getSize());
    std::cout << "----------" << std::endl;
}

//test insert a note that is already into the collection
TEST(Collection, addNoteInvalid) {
    std::cout << "add note invalid" << std::endl;
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    Note note2("title1", "text1", false);
    collection.addNote(note1);
    collection.addNote(note2);
    ASSERT_EQ(1, collection.getSize());
    std::cout << "----------" << std::endl;
}

//test remove a note from collection
TEST(Collection, removeNote) {
    std::cout << "remove note" << std::endl;
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    collection.addNote(note1);
    ASSERT_EQ(1, collection.getSize());
    collection.removeNote(note1);
    ASSERT_EQ(0, collection.getSize());
    std::cout << "----------" << std::endl;
}

//test remove a note that isn't in the collection
TEST(Collection, removeNoteInvalid) {
    std::cout << "remove note invalid" << std::endl;
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    Note note2("title2", "text2", false);
    collection.addNote(note1);
    collection.removeNote(note2);
    ASSERT_EQ(1, collection.getSize());
    std::cout << "----------" << std::endl;
}

//test show a note that is in the collection
TEST(Collection, showNote) {
    std::cout << "show note" << std::endl;
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    collection.addNote(note1);
    Note note = collection.findNote("title1");
    std::cout << note.toString() << std::endl;
    ASSERT_EQ(1, collection.getSize());
    ASSERT_EQ(note.toString(), "title1 text1 unlocked");
    std::cout << "----------" << std::endl;
}

//test show a note that isn't in the collection
TEST(Collection, showNoteInvalid) {
    std::cout << "show note invalid" << std::endl;
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    Note note2("title2", "text2", false);
    collection.addNote(note1);
    Note note = collection.findNote("title2");
    std::cout << note.toString() << std::endl;
    ASSERT_EQ(1, collection.getSize());
    ASSERT_EQ(note.toString(), "  unlocked");

    std::cout << "----------" << std::endl;
}

//test update a note that is in the collection
TEST(Collection, updateNote) {
    std::cout << "update note" << std::endl;
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    collection.addNote(note1);
    collection.updateNote(note1, "title", "text");
    ASSERT_EQ(1, collection.getSize());
    std::cout << "----------" << std::endl;
}

//test update a note that isn't in the collection
TEST(Collection, updateNoteInvalid) {
    std::cout << "update note invalid" << std::endl;
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    Note note2("title2", "text2", false);
    collection.addNote(note1);
    collection.updateNote(note2, "title", "text");
    ASSERT_EQ(1, collection.getSize());
    std::cout << "----------" << std::endl;
}

//test update locked attribute
TEST(Collection, updateLocked) {
    std::cout << "update locked" << std::endl;
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    collection.addNote(note1);
    collection.updateLocked(note1);
    ASSERT_EQ(1, collection.getSize());
    std::cout << "----------" << std::endl;
}

//test fail update locked attribute
TEST(Collection, updateLockedIvalid) {
    std::cout << "update locked invalid" << std::endl;
    Collection collection("1", false);
    Note note1("title1", "text1", false);
    Note note2("title2", "text2", false);
    collection.addNote(note1);
    collection.updateLocked(note2);
    ASSERT_EQ(1, collection.getSize());
    std::cout << "----------" << std::endl;
}

//test notify observers
TEST(Collection, notifyObserver) {
    std::cout << "notify observers" << std::endl;
    Collection collection("1", false);
    NoteCounter notecounter(collection);
    LockedNotesCounter lockednotes(collection);
    Note note1("title1", "text1", false);
    Note note2("title2", "text2", false);
    Note note3("title3", "text3", true);
    collection.addNote(note1);
    collection.addNote(note2);
    collection.addNote(note3);
    collection.updateLocked(note2);
    collection.removeNote(note1);
    collection.removeNote(note3);
    ASSERT_EQ(2, collection.getSize());
    std::cout << "----------" << std::endl;
}