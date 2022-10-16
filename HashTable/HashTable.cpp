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
    std::copy(b.chain, b.chain + sizeOfArray, chain);
}

HashTable::HashTable(HashTable&& b) : sizeOfArray(b.sizeOfArray) {
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
    //???
    sizeOfArray = b.sizeOfArray;
    std::copy(b.chain, b.chain + sizeOfArray,chain);
    return *this;
}

HashTable& HashTable::operator=(HashTable&& b) {
    if (this == &b) {
        return *this;
    }
    sizeOfArray = b.sizeOfArray;
    chain = b.chain;
    b.chain = nullptr;
    b.sizeOfArray = 0;
    return *this;
}

void HashTable::Clear() {
    for (size_t i = 0; i < sizeOfArray; i++) {
        chain[i].clear();
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
    //????????????????? cache
    size_t size = 0;
    for (size_t i = 0; i < sizeOfArray; ++i) {
        size += chain[i].size();
    }
    return size;
}

bool HashTable::Empty() const {
    return (Size() == 0);
}

bool operator==(const HashTable& a, const HashTable& b) {
    size_t sizeA = a.sizeOfArray;
    size_t sizeB = b.sizeOfArray;
    if (sizeA != sizeB) {
        return false;
    }
    for (size_t i = 0; i < sizeA; ++i) {
        if (a.chain[i].size() != b.chain[i].size()) {
            return false;
        }
        if (a.chain[i] != b.chain[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const HashTable& a, const HashTable& b) {
    return !(a == b);
}
