#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>

typedef std::string Key;

class Strategy {
    Strategy(Key key);
    // принимаем файл, считываем его, идем по нему
    // принимаем действие: пасовать, брать карту
    Key key;
};

#endif
