#include "HashTable.h"

HashTable::HashTable() {
    chain = new std::list <TValue> [sizeOfArray];    
}

HashTable::~HashTable() {
    delete[] chain;
}

HashTable::HashTable(const HashTable& b) {
    size_t size = Size(b);
    chain = new std::list <TValue> (size);
    for (int i = 0; i < size; ++i) {
        chain[i] = b.chain[i];
    }
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
    size_t size = Size(b);
    for (int i = 0; i < size; ++i) {
        chain[i] = b.chain[i];
    }
    return *this;
}

void HashTable::Clear() {
    for (int i = 0; i < sizeOfArray; i++) {
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

int HashTable::Hashing(const Key& k) {
    int sum = 0, p = 7;
    for (int i = 0; i < k.length(); ++i) {
        sum += (int)k[i] * p;
        p *= 7;
    }
    int hash = (11 * sum + 7) % sizeOfArray;
    return hash;
}

bool HashTable::Insert(const Key& k, const Value& v) {
    if (Contains(k) == true) {
        return false;
    }
    int hash = Hashing(k);
    chain[hash].push_back(v);
    double coef = Size(*this) / sizeOfArray;
    // if (coef > 0.7) {
    //     sizeOfArray *= 2;
    //     HashTable b = HashTable();
    //     Rehashing(*this);
    // } // переместить
    return true;
}

    // // Проверка наличия значения по заданному ключу.
bool HashTable::Contains(const Key& k) { // Когда функция константная, он ругается на Hashing, не могу понять почему
    int hash = Hashing(k);
    for (auto i = chain[hash].begin(); i != chain[hash].end(); ++i) {
        if (i->name == k) {
            return true;
        }
    }
    return false;
}

    // // Возвращает значение по ключу. Небезопасный метод.
    // // В случае отсутствия ключа в контейнере, следует вставить в контейнер
    // // значение, созданное конструктором по умолчанию и вернуть ссылку на него. 
Value& HashTable::operator[](const Key& k) {

}

Value& HashTable::At(const Key& k) {

}
const Value& HashTable::At(const Key& k) const {

}

size_t HashTable::Size(const HashTable& b) const {
    int size = 0;
    for (int i = 0; i < sizeOfArray; ++i) {
        size += chain[i].size();
    }
    return size;
}

bool HashTable::Empty() const {
    if (Size(*this) != 0) {
        return false;
    }
    return true;
}

bool operator==(const HashTable& a, const HashTable& b) {
    int sizeA = a.sizeOfArray;
    int sizeB = b.sizeOfArray;
    if (a != b) {
        return false;
    }
    for (int i = 0; i < sizeA; ++i) {
        if (a.chain[i] != b.chain[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const HashTable& a, const HashTable& b) {
    return !(a == b);
}
