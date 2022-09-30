#include "TValue.h"

bool operator==(const TValue& a, const TValue& b) {
    if ((a.age == b.age) && (a.name == b.name) && (a.weight == b.weight)) {
        return true;
    }
    return false;
}

bool operator!=(const TValue& a, const TValue& b) {
    return !(a == b);
}
