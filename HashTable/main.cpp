#include "HashTable.h"
#include <gtest/gtest.h>

TEST(EmptyInvariant, temp) {
    HashTable hashTable;
    EXPECT_TRUE(hashTable.Empty());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    // HashTable hashTable;
    // return 0;
}