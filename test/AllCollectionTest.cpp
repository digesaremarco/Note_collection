
#include "gtest/gtest.h"
#include "../AllCollection.h"

TEST(Collection, addCollection){
    Collection collection("1", false);
    AllCollection allCollection;
    allCollection.addCollection(collection);
    ASSERT_EQ(1, allCollection.getSize());  //size value expect to be 1
}