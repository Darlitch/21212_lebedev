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

TEST(Operations, Insert) {
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    EXPECT_TRUE(a.Contains("aboba"));
    a.Insert("aboba", v);
    EXPECT_TRUE(a.Size() == 1);
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

TEST(Operations, Clean) {
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    a.Clear();
    EXPECT_TRUE(a.Empty());
}

TEST(Operations, Size) {
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    EXPECT_TRUE(a.Size() == 1);
    a.Clear();
    EXPECT_TRUE(a.Size() == 0);
}

TEST(Operations, Empty) {
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    EXPECT_FALSE(a.Empty());
    a.Clear();
    EXPECT_TRUE(a.Empty());
}

TEST(Operations, Contains) {
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    EXPECT_FALSE(a.Contains("abba"));
    EXPECT_FALSE(a.Contains("ababa"));
    EXPECT_TRUE(a.Contains("aboba"));
    a.Clear();
    EXPECT_FALSE(a.Contains("aboba"));
}

// TEST(Operations, Hashing) {
//     int hash1 = HashTable::Hashing("aboba");
//     int hash2 = HashTable::Hashing("aobba");
//     EXPECT_FALSE(hash1 == hash2);

// }

TEST(Operations, At) {

}

TEST(Operations, AtConst) {

}

TEST(Operators, OperatorEqual) {
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

TEST(Operators, OperatorCompare) {
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    HashTable b;
    b = a;
    EXPECT_TRUE(a == b);
    b.Clear();
    EXPECT_TRUE(a != b);
    b.Insert("aboba", v);
    EXPECT_TRUE(a == b);
}

TEST(Operators, OperatorInd) {
    
}

TEST(Universal, MoveAndSwap) {
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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
