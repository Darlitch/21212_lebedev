#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <list>

#include "TValue.h"

// В этой задаче для простоты не требуется делать контейнер шаблонным,
// это допускается по желанию. Для нешаблонного решения, 
// введем типы ключей и значений: ключом будет выступать строка (например, имя
// студента, значением - произвольная структура (например, численные
// характеристики студента.
typedef std::string Key; 

class HashTable {
public:
    HashTable();
    HashTable(size_t lastSizeOA);
    ~HashTable();

    // конструктор копирования
    HashTable(const HashTable& b);
    // Конструктор перемещения
    HashTable(HashTable&& b);

    HashTable& Rehashing();

    // Обменивает значения двух хэш-таблиц.
    // Подумайте, зачем нужен этот метод, при наличии стандартной функции
    // std::swap.
    void Swap(HashTable& b);

    HashTable& operator=(const HashTable& b);
    HashTable& operator=(HashTable&& b);

    // Очищает контейнер.
    void Clear();
    // Удаляет элемент по заданному ключу.
    bool Erase(const Key& k);
    // Вставка в контейнер. Возвращаемое значение - успешность вставки.
    size_t Hashing(const Key& k) const;
    bool Insert(const Key& k, const TValue& v);

    // Проверка наличия значения по заданному ключу.
    bool Contains(const Key& k) const;

    // Возвращает значение по ключу. Небезопасный метод.
    // В случае отсутствия ключа в контейнере, следует вставить в контейнер
    // значение, созданное конструктором по умолчанию и вернуть ссылку на него. 
    TValue& operator[](const Key& k);

    // Возвращает значение по ключу. Бросает исключение при неудаче.
    TValue& At(const Key& k);
    const TValue& At(const Key& k) const;

    size_t Size() const;
    bool Empty() const;

    friend bool operator==(const HashTable& a, const HashTable& b);
    friend bool operator!=(const HashTable& a, const HashTable& b);

private:
    // size_t size = 0;
    size_t sizeOfArray = 10000;
    std::list <TValue>* chain;
};

#endif
