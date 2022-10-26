#ifndef FACTORY_H
#define FACTORY_H

#include <map>

#include "Strategy.h"

typedef std::string Key;

class StratFactory {
public:
    StratFactory();
    // Добавляет в map стратегию
    void RegisterStrat(const Key&, Bot* (*)());
    // Обращается в map для создания стратегии
    Bot* CreateStrat(const Key& key);
private:
    std::map <Key, Bot* (*)()> Strats;
};

#endif
