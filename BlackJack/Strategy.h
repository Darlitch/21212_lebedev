#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>

class AbstractStrategy {
public:
    // конструктор
    // AbstractStrategy(std::string key);
    // virtual int StratChoise(AbstractStrategy& opponent);
    virtual stratCreator() {}
    virtual Strat* create() const = 0;

    // принимаем файл, считываем его, идем по нему
    // принимаем действие: пасовать, брать карту
    // std::string key;
private:
};

#endif
