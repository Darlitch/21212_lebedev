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
    v.name = "ababa";
    a.Insert("ababa", v);
    EXPECT_TRUE(a.Contains("ababa"));
    v.name = "abiba";
    a.Insert("abiba", v);
    EXPECT_TRUE(a.Contains("abiba"));
    v.name = "abibi";
    a.Insert("abibi", v);
    EXPECT_TRUE(a.Contains("abibi"));
    v.name = "ibibi";
    a.Insert("ibibi", v);
    EXPECT_TRUE(a.Contains("ibibi"));
    EXPECT_TRUE(a.Size() == 5);
}

TEST(Operations, Erase) {
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    a.Erase("aboba");
    v.name = "ababa";
    a.Insert("ababa", v);
    v.name = "abiba";
    a.Insert("abiba", v);
    v.name = "abibi";
    a.Insert("abibi", v);
    v.name = "ibibi";
    a.Insert("ibibi", v);
    a.Erase("ababa");
    a.Erase("abiba");
    a.Erase("abibi");
    a.Erase("ibibi");
    EXPECT_FALSE(a.Contains("aboba"));
    EXPECT_FALSE(a.Contains("ababa"));
    EXPECT_FALSE(a.Contains("abiba"));
    EXPECT_FALSE(a.Contains("abibi"));
    EXPECT_FALSE(a.Contains("ibibi"));
}

TEST(Operations, Clean) {
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    v.name = "ababa";
    a.Insert("ababa", v);
    v.name = "abiba";
    a.Insert("abiba", v);
    v.name = "abibi";
    a.Insert("abibi", v);
    v.name = "ibibi";
    a.Insert("ibibi", v);
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
    v.name = "ababa";
    a.Insert("ababa", v);
    v.name = "abiba";
    a.Insert("abiba", v);
    v.name = "abibi";
    a.Insert("abibi", v);
    v.name = "ibibi";
    a.Insert("ibibi", v);
    EXPECT_TRUE(a.Size() == 5);
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
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    TValue b = a.At("aboba");
    EXPECT_TRUE(v == b);
}

// TEST(Operations, AtConst) {
//     const HashTable a;
//     TValue v;
//     v.name = "aboba";
//     v.age = 18;
//     v.weight = 15;
//     a.Insert("aboba", v);
//     TValue b = a.At("aboba");
//     EXPECT_TRUE(v == b);
// }

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
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    EXPECT_TRUE(a["aboba"] == v);
    a["abiba"];
    EXPECT_TRUE(a.Contains("abiba"));
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

TEST(Universal, Rehashing) {
    HashTable a;
    TValue v;
    v.name = "aboba";
    v.age = 18;
    v.weight = 15;
    a.Insert("aboba", v);
    v.name = "ababa";
    a.Insert("ababa", v);
    v.name = "abiba";
    a.Insert("abiba", v);
    v.name = "abibi";
    a.Insert("abibi", v);
    v.name = "ibibi";
    a.Insert("ibibi", v);
    a.Rehashing();
    EXPECT_TRUE(a.Size() == 5);
    EXPECT_TRUE(a.Contains("aboba"));
    EXPECT_TRUE(a.Contains("ababa"));
    EXPECT_TRUE(a.Contains("abiba"));
    EXPECT_TRUE(a.Contains("abibi"));
    EXPECT_TRUE(a.Contains("ibibi"));
    HashTable b = a;
    EXPECT_TRUE(b.Size() == 5);
    EXPECT_TRUE(b.Contains("aboba"));
    EXPECT_TRUE(b.Contains("ababa"));
    EXPECT_TRUE(b.Contains("abiba"));
    EXPECT_TRUE(b.Contains("abibi"));
    EXPECT_TRUE(b.Contains("ibibi"));
    v.name = "Imposter";
    b.Insert("Imposter", v);
    a = b;
    EXPECT_TRUE(a == b);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
