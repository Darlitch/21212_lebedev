#ifndef STRAT_FACTORY_H
#define STRAT_FACTORY_H

#include <map>

#include "Strategy.h"

template <class Strat>
class StratFactory {
public:
    StratFactory() {}
    ~StratFactory();
    StratFactory(StratFactory&) = delete;
    StratFactory& operator=(StratFactory&) = delete;
    // Добавляет в map стратегию
    void RegisterStrat(const std::string& key, Strat (*Func)()) {
        typename FactoryMap::iterator it = stratFactory.find(key);
        if (it == stratFactory.end()) {
            stratFactory[key] = Func;
        }
    }
    // Обращается в map для создания стратегии
    Strat CreateStrat(const std::string& key) {
        typename FactoryMap::iterator it = stratFactory.find(key);
        if (it != stratFactory.end()) {
            return it->second();
        }
        return 0;
    }
private:
    typedef std::map <std::string, Strat(*Func)()> FactoryMap;
    FactoryMap stratFactory;
};

#endif
