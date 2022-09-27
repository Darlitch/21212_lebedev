#include "HashTable.h"

HashTable::HashTable() {
    chain = new std::list <TValue> (1000);    
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
    Clear(this); // надо ли?
    size_t size = Size(b);
    for (int i = 0; i < size; ++i) {
        chain[i] = b.chain[i];
    }
    return *this;
}

    // // Очищает контейнер.
void HashTable::Clear() {

}
    // // Удаляет элемент по заданному ключу.
bool HashTable::Erase(const Key& k) {

}
    // // Вставка в контейнер. Возвращаемое значение - успешность вставки.
bool HashTable::Insert(const Key& k, const Value& v) {

}

    // // Проверка наличия значения по заданному ключу.
bool HashTable::Contains(const Key& k) const {

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
