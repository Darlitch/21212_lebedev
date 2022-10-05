#ifndef TVALUE_H
#define TVALUE_H

#include <iostream>

typedef std::string Key;

struct TValue {
    Key name = Key();
    unsigned age = 0;
    unsigned weight = 0;
    friend bool operator==(const TValue& a, const TValue& b);
    friend bool operator!=(const TValue& a, const TValue& b);
};

#endif
