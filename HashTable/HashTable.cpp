#include "HashTable.h"

HashTable::HashTable() {
    chain = new std::list <TValue> (sizeOfArray);    
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

    // // Подумайте, зачем нужен этот метод, при наличии стандартной функции
    // // std::swap.
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

    // // Очищает контейнер.
void HashTable::Clear() {
    for (int i = 0; i < sizeOfArray; i++) {
        chain[i].clear();
    }

}
    // // Удаляет элемент по заданному ключу.
bool HashTable::Erase(const Key& k) {
    int sum = 0, p = 7;
    for (int i = 0; i < k.length(); ++i) {
        sum += (int)k[i] * p;
        p *= 7;
    }
    int hash = (11 * sum + 7) % sizeOfArray;
}
    // // Вставка в контейнер. Возвращаемое значение - успешность вставки.
bool HashTable::Insert(const Key& k, const Value& v) {
    int sum = 0, p = 7;
    for (int i = 0; i < k.length(); ++i) {
        sum += (int)k[i] * p;
        p *= 7;
    }
    int hash = (11 * sum + 7) % sizeOfArray;
    chain[hash].push_back(v);
    // std::list <TValue>* temp(std::move(&chain[hash]));
    // while (std::next(temp, 1) != nullptr) {
    //     temp = std::next(temp, 1);
    // }

    //доделать увеличение массива
    return true;
}

    // // Проверка наличия значения по заданному ключу.
bool HashTable::Contains(const Key& k) const {
    int sum = 0, p = 7;
    for (int i = 0; i < k.length(); ++i) {
        sum += (int)k[i] * p;
        p *= 7;
    }
    int hash = (11 * sum + 7) % sizeOfArray;
    //дописать
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

}

bool HashTable::Empty() const {

}

bool operator==(const HashTable& a, const HashTable& b) {

}
bool operator!=(const HashTable& a, const HashTable& b) {

}
