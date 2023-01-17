#include <algorithm>

#include "HashTable.h"

namespace {

size_t CalcHash(const Key& k) {
    size_t sum = 0, p = 7;
    for (size_t i = 0; i < k.length(); ++i) {
        sum += (size_t)k[i] * p;
        p *= 7;
    }
    size_t hash = (11 * sum + 7);
    return hash;
}

}

HashTable::HashTable() {
    chain = new std::list <TValue> [sizeOfArray];    
}

HashTable::HashTable(size_t lastSizeOA) : sizeOfArray(lastSizeOA) {
    chain = new std::list <TValue> [sizeOfArray];    
}

HashTable::~HashTable() {
    delete[] chain;
}

HashTable::HashTable(const HashTable& b) : sizeOfArray(b.sizeOfArray) {
    chain = new std::list <TValue> [sizeOfArray];
    // std::copy(b.chain, b.chain + sizeOfArray, chain);
    for (size_t i = 0; i < b.sizeOfArray; ++i) {
        for (auto j: b.chain[i]) {
            Insert(j.name, j);
        }
    }
}

HashTable::HashTable(HashTable&& b) : size(b.size), sizeOfArray(b.sizeOfArray) {
    chain = b.chain;
    b.chain = nullptr;
    b.sizeOfArray = 0;
}

HashTable& HashTable::Rehashing() {
    HashTable b(sizeOfArray * 2);
    for (size_t i = 0; i < sizeOfArray; ++i) {
        for (auto i: chain[i]) {
            b.Insert(i.name, i);
        }
    }
    b.sizeOfArray = sizeOfArray*2;
    b.Swap(*this);
    return *this;
}

void HashTable::Swap(HashTable& b) {
    HashTable temp = std::move(*this);
    *this = std::move(b);
    b = std::move(temp);
}

HashTable& HashTable::operator=(const HashTable& b) {
    if (this == &b) {
        return *this;
    }
    delete[] chain;
    chain = new std::list <TValue> [b.sizeOfArray];
    sizeOfArray = b.sizeOfArray;
    size = 0;
    // std::copy(b.chain, b.chain + sizeOfArray,chain); Почему не работает так как я хочу?
    for (size_t i = 0; i < b.sizeOfArray; ++i) {
        for (auto j: b.chain[i]) {
            Insert(j.name, j);
        }
    }
    return *this;
}

HashTable& HashTable::operator=(HashTable&& b) {
    if (this == &b) {
        return *this;
    }
    delete[] chain;
    sizeOfArray = b.sizeOfArray;
    size = b.size;
    chain = b.chain;
    b.chain = nullptr;
    b.sizeOfArray = 0;
    return *this;
}

void HashTable::Clear() {
    for (size_t i = 0; i < sizeOfArray; i++) {
        chain[i].clear();
        size = 0;
    }
}

bool HashTable::Erase(const Key& k) {
    size_t hash = Hashing(k);
    for (auto i = chain[hash].begin(); i != chain[hash].end(); ++i) {
        if (i->name == k) {
            chain[hash].erase(i);
            return true;
        }
    }
    size--;
    return false;
}

size_t HashTable::Hashing(const Key& k) const {
    return CalcHash(k) % sizeOfArray;
}

bool HashTable::Insert(const Key& k, const TValue& v) {
    if (Contains(k) == true) {
        return false;
    }
    size_t hash = Hashing(k);
    chain[hash].push_back(v);
    size++;
    return true;
}

bool HashTable::Contains(const Key& k) const {
    size_t hash = Hashing(k);
    for (auto i : chain[hash]) {
        if (i.name == k) {
            return true;
        }
    }
    return false;
}

TValue& HashTable::operator[](const Key& k) {
    if (Contains(k)) {
        return At(k);
    }
    TValue v;
    v.name = k;
    Insert(k,v);
    size++;
    return At(k);
}

TValue& HashTable::At(const Key& k) {
    if (Contains(k)) {
        size_t hash = Hashing(k);
        for (auto& i : chain[hash]) {
            if (i.name == k) {
                return i;
            }
        }
    }
    throw std::invalid_argument("There is no such element");
}

const TValue& HashTable::At(const Key& k) const {
    if (Contains(k)) {
        size_t hash = Hashing(k);
        for (auto& i : chain[hash]) {
            if (i.name == k) {
                return i;
            }
        }
    }
    throw std::invalid_argument("There is no such element");
}

size_t HashTable::Size() const {
    return size;
}

bool HashTable::Empty() const {
    return (Size() == 0);
}

bool operator==(const HashTable& a, const HashTable& b) {
    if (a.Size() != b.Size()) {
        return false;
    }
    for (size_t i = 0; i < a.sizeOfArray; ++i) {
        for (auto j: a.chain[i]) {
            if (!b.Contains(j.name)) {
                return false;
            }
        }
    }
    for (size_t i = 0; i < b.sizeOfArray; ++i) {
        for (auto j: b.chain[i]) {
            if (!a.Contains(j.name)) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const HashTable& a, const HashTable& b) {
    return !(a == b);
}
