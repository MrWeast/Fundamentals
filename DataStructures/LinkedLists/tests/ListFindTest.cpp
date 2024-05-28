#include "../include/UnsortedLinkedList.hpp"
#include "../include/SortedLinkedList.hpp"
#include <gtest/gtest.h>


// Parameterized test fixture for data structures
template<typename T>
class ListTest : public ::testing::Test {
protected:
    T* ds = nullptr;

    void SetUp() override {
        ds = new T();
    }

    void TearDown() override {
        delete ds;
        ds = nullptr;
    }
};

using ListTypes = ::testing::Types<UnsortedLinkedList, SortedLinkedList>;
TYPED_TEST_SUITE(ListTest, ListTypes);

TYPED_TEST(ListTest, FindTest) {
    TypeParam* list = new TypeParam();
    list->insert(1);
    list->insert(2);
    list->insert(3);
    list->insert(4);
    list->insert(5);

    EXPECT_EQ(list->find(1)->val(),1);
    EXPECT_EQ(list->find(2)->val(),2);
    EXPECT_EQ(list->find(3)->val(),3);
    EXPECT_EQ(list->find(4)->val(),4);
    EXPECT_EQ(list->find(5)->val(),5);
    EXPECT_EQ(list->find(6),nullptr);
    EXPECT_EQ(list->find(7),nullptr);
    EXPECT_EQ(list->find(8),nullptr);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
