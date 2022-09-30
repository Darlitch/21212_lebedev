#include <iostream>

typedef std::string Key;

typedef struct Value {
    Key name = Key();
    unsigned age = 0;
    unsigned weight = 0;
    friend bool operator==(const TValue& a, const TValue& b);
    friend bool operator!=(const TValue& a, const TValue& b);
}TValue;