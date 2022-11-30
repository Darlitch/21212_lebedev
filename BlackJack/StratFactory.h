#ifndef FACTORY_H
#define FACTORY_H

#include <map>

#include "Strategy.h"

class StratFactory {
public:
    StratFactory();
    // Добавляет в map стратегию
    void RegisterStrat(const std::string&, Bot* (*)());
    // Обращается в map для создания стратегии
    Bot* CreateStrat(const std::string& key);
private:
    std::map <std::string, Bot* (*)()> Strats;
};

#endif
