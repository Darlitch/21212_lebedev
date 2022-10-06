#include "HashTable.h"
#include <gtest/gtest.h>

TEST(Constructors, Default) {
    HashTable a;
    EXPECT_TRUE(a.Empty());
}

TEST(Constructors, Copy) {
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    HashTable b = a;
    EXPECT_TRUE(b.Contains("aboba"));
}

TEST(Constructors, OperatorEqual) {
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    HashTable b;
    b = a;
    EXPECT_TRUE(b.Contains("aboba"));
}

TEST(Constructors, OperatorMoveAndSwap) {
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    HashTable b;
    b.Swap(a);
    EXPECT_TRUE(b.Contains("aboba"));
    EXPECT_FALSE(a.Contains("aboba"));
}

TEST(Operations, Insert) {
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    EXPECT_TRUE(a.Contains("aboba"));
}

TEST(Operations, Erase) {
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    a.Erase("aboba");
    EXPECT_FALSE(a.Contains("aboba"));
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
