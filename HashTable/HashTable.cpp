#include <algorithm>

#include "HashTable.h"

namespace {

int CalcHash(const Key& k) {
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

HashTable::~HashTable() {
    delete[] chain;
}

HashTable::HashTable(const HashTable& b) : sizeOfArray{b.sizeOfArray} {
    chain = new std::list <TValue> (sizeOfArray);
    std::copy(b.chain, b.chain + sizeOfArray,chain);
}

HashTable::HashTable(HashTable&& b) {
    this->chain = b.chain;
    b.chain = nullptr;
}

// HashTable& HashTable::Rehashing(HashTable& b) {

// }

void HashTable::Swap(HashTable& b) {
    std::list <TValue>* temp(std::move(this->chain));
    this->chain = b.chain;
    b.chain = temp;
}

HashTable& HashTable::operator=(const HashTable& b) {
    if (this == &b) {
        return *this;
    }
    sizeOfArray = b.sizeOfArray;
    std::copy(b.chain, b.chain + sizeOfArray,chain);
    return *this;
}

void HashTable::Clear() {
    for (size_t i = 0; i < sizeOfArray; i++) {
        chain[i].clear();
    }
}

bool HashTable::Erase(const Key& k) {
    int hash = Hashing(k);
    for (auto i = chain[hash].begin(); i != chain[hash].end(); ++i) {
        if (i->name == k) {
            chain[hash].erase(i);
            return true;
        }
    }
    return false;
}

int HashTable::Hashing(const Key& k) const {
    return CalcHash(k) % sizeOfArray;
}

bool HashTable::Insert(const Key& k, const TValue& v) {
    if (Contains(k) == true) {
        return false;
    }
    int hash = Hashing(k);
    chain[hash].push_back(v);
    // double coef = Size(*this) / sizeOfArray;
    // if (coef > 0.7) {
    //     sizeOfArray *= 2;
    //     HashTable b = HashTable();
    //     Rehashing(*this);
    // } // переместить
    return true;
}

    // // Проверка наличия значения по заданному ключу.
bool HashTable::Contains(const Key& k) const { // Когда функция константная, он ругается на Hashing, не могу понять почему
    int hash = Hashing(k);
    for (auto i : chain[hash]) {
        if (i.name == k) {
            return true;
        }
    }
    return false;
}

    // // Возвращает значение по ключу. Небезопасный метод.
    // // В случае отсутствия ключа в контейнере, следует вставить в контейнер
    // // значение, созданное конструктором по умолчанию и вернуть ссылку на него. 
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
        throw std::invalid_argument("There is no such element");
    }
    int hash = Hashing(k);
    for (auto i : chain[hash]) {
        if (i.name == k) {
            return i;
        }
    }
}

const TValue& HashTable::At(const Key& k) const {
    if (Contains(k)) {
        throw std::invalid_argument("There is no such element");
    }
    int hash = Hashing(k);
    for (auto i : chain[hash]) {
        if (i.name == k) {
            return i;
        }
    }
}

// int main() {
//     HashTable h;
//     h["test"] = {};
//     h.at("test");

//     const HashTable h2;
//     h2.at();

// }

size_t HashTable::Size() const {
    size_t size = 0;
    for (size_t i = 0; i < sizeOfArray; ++i) {
        size += chain[i].size();
    }
    return size;
}

bool HashTable::Empty() const {
    return (Size() != 0); // доделать
}

bool operator==(const HashTable& a, const HashTable& b) {
    size_t sizeA = a.sizeOfArray;
    size_t sizeB = b.sizeOfArray;
    if (sizeA != sizeB) {
        return false;
    }
    for (size_t i = 0; i < sizeA; ++i) {
        size_t sizeAc = a.chain[i].size();
        size_t sizeBc = b.chain[i].size();
        if (sizeAc != sizeBc) {
            return false;
        }
        for (size_t j = 0; j < sizeA; ++j) {
            auto itA = a.chain[i].begin();
            auto itB = b.chain[i].begin();
            if (itA != itB) {
                return false;
            }
            itA++;
            itB++;
        }
    }
    return true;
}

bool operator!=(const HashTable& a, const HashTable& b) {
    return !(a == b);
}
