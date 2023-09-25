
#include "gtest/gtest.h"
#include "../AllCollection.h"

//test insert new collection
TEST(Collection, addCollection) {
    std::cout << "add collection" << std::endl;
    Collection collection("1", false);
    AllCollection allCollection;
    allCollection.addCollection(collection);
    ASSERT_EQ(1, allCollection.getSize());
    std::cout << "----------" << std::endl;
}

//test insert new collection that is already in the list
TEST(Collection, addCollectionInvalid) {
    std::cout << "add collection invalid" << std::endl;
    Collection collection("1", false);
    Collection collection2("1", false);
    AllCollection allCollection;
    allCollection.addCollection(collection);
    allCollection.addCollection(collection2);
    ASSERT_EQ(1, allCollection.getSize());
    std::cout << "----------" << std::endl;
}

//test remove collection
TEST(Collection, removeCollection) {
    std::cout << "remove collection" << std::endl;
    Collection collection("1", false);
    AllCollection allCollection;
    allCollection.addCollection(collection);
    allCollection.removeCollection(collection);
    ASSERT_EQ(0, allCollection.getSize());
    std::cout << "----------" << std::endl;
}

//test remove collection that isn't in the list
TEST(Collection, removeCollectionInvalid) {
    std::cout << "remove collection invalid" << std::endl;
    Collection collection("1", false);
    Collection collection2("2", false);
    AllCollection allCollection;
    allCollection.addCollection(collection);
    allCollection.removeCollection(collection2);
    ASSERT_EQ(1, allCollection.getSize());
    std::cout << "----------" << std::endl;
}

//test add note to collection
TEST(Collection, addNoteCollection) {
    std::cout << "add note to collection" << std::endl;
    Collection collection("1", false);
    AllCollection allCollection;
    allCollection.addCollection(collection);
    Note note("title", "text", false);
    allCollection.addNote(note, collection);
    ASSERT_EQ(1, allCollection.getSize());
    std::cout << "----------" << std::endl;
}

//test add note to collection that isn't in the list
TEST(Collection, addNoteCollectionIvalid) {
    std::cout << "add note to collection" << std::endl;
    Collection collection("1", false);
    Collection collection2("2", false);
    AllCollection allCollection;
    allCollection.addCollection(collection);
    Note note("title", "text", false);
    allCollection.addNote(note, collection2);
    ASSERT_EQ(1, allCollection.getSize());
    std::cout << "----------" << std::endl;
}