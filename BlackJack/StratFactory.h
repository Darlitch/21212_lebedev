#ifndef STRAT_FACTORY_H
#define STRAT_FACTORY_H

#include <map>

#include "Strategy.h"

class StratFactory {
public:
    StratFactory();
    ~virtual StratFactory();
    template <class Strat>
    // Добавляет в map стратегию
    void RegisterStrat(const std::string& key);
    // Обращается в map для создания стратегии
    Strat* CreateStrat(const std::string& key);
private:
    typedef std::map <std::string, AbstractStrategy<Strat>*> FactoryMap;
    FactoryMap stratFactory;
};

#endif
