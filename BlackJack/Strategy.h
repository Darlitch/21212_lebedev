#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>

class Strategy {
public:
    // конструктор
    Strategy(std::string key);
    virtual int StratChoise(Strategy& opponent);

    // принимаем файл, считываем его, идем по нему
    // принимаем действие: пасовать, брать карту
    std::string key;
private:
};

#endif
