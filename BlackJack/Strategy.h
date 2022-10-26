#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>

typedef std::string Key;

struct TCard {
    size_t Value = 0;
    size_t Count = 0;
};

class Strategy {
public:
    // конструктор
    Strategy(Key key);
    virtual int StratChoise(Strategy& opponent);
    // возвращает количество очков в руке Стратегии
    size_t GetHand();
    // возвращает счет Стратегии в турнире
    size_t GetScore();

    // очищает руку (для турниров)
    void ClearHand();

    // принимаем файл, считываем его, идем по нему
    // принимаем действие: пасовать, брать карту
    Key key;
private:
    size_t hand = 0;
    size_t score = 0;
};

#endif
