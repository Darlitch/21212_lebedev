#include <iostream>
#include <list>
// В этой задаче для простоты не требуется делать контейнер шаблонным,
// это допускается по желанию. Для нешаблонного решения, 
// введем типы ключей и значений: ключом будет выступать строка (например, имя
// студента, значением - произвольная структура (например, численные
// характеристики студента.
typedef std::string Key;

typedef struct Value {
    Key name;
    unsigned age;
    unsigned weight;
}TValue;

class HashTable {
public:
    HashTable();
    ~HashTable();

    // конструктор копирования
    HashTable(const HashTable& b);
    // Конструктор перемещения
    HashTable(HashTable&& b);

    // Обменивает значения двух хэш-таблиц.
    // Подумайте, зачем нужен этот метод, при наличии стандартной функции
    // std::swap.
    void Swap(HashTable& b);

    HashTable& operator=(const HashTable& b);

    // Очищает контейнер.
    void Clear();
    // Удаляет элемент по заданному ключу.
    bool Erase(const Key& k);
    // Вставка в контейнер. Возвращаемое значение - успешность вставки.
    int Hashing(const Key& k);
    bool Insert(const Key& k, const Value& v);

    // Проверка наличия значения по заданному ключу.
    bool Contains(const Key& k) const;

    // Возвращает значение по ключу. Небезопасный метод.
    // В случае отсутствия ключа в контейнере, следует вставить в контейнер
    // значение, созданное конструктором по умолчанию и вернуть ссылку на него. 
    Value& operator[](const Key& k);

    // Возвращает значение по ключу. Бросает исключение при неудаче.
    Value& At(const Key& k);
    const Value& At(const Key& k) const;

    size_t Size(const HashTable& b) const;
    bool Empty() const;

    friend bool operator==(const HashTable& a, const HashTable& b);
    friend bool operator!=(const HashTable& a, const HashTable& b);
private:
    std::list <TValue>* chain;
    int sizeOfArray = 1000;
};
