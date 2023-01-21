#ifndef STRAT_FACTORY_H
#define STRAT_FACTORY_H

#include <map>

template <class TypeKey, class Base, class ProductType = Base *(*)()>
class StratFactory {
public:
    StratFactory() {}
    ~StratFactory() {}
    StratFactory(StratFactory&) = delete;
    StratFactory& operator=(StratFactory&) = delete;
    // Добавляет в map стратегию
    bool RegisterStrat(const TypeKey& key, ProductType Func) {
        auto it = stratFactory.find(key);
        if (it == stratFactory.end()) {
            stratFactory[key] = Func;
            return true;
        }
        return false;
    }
    // Обращается в map для создания стратегии
    Base* CreateStrat(const TypeKey& key) {
        auto it = stratFactory.find(key);
        if (it != stratFactory.end()) {
            return it->second();
        }
        return 0;
    }
    static StratFactory* GetInstance() {
        // if (&factory == nullptr) {
            static StratFactory factory;
        // }
        return &factory;
    }
private:
    typedef std::map <TypeKey, Base*(*)()> FactoryMap;
    FactoryMap stratFactory;
};

#endif
