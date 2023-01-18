#ifndef STRAT_FACTORY_H
#define STRAT_FACTORY_H

#include <map>

template <class TypeKey, class Base>
class StratFactory {
public:
    StratFactory() {}
    ~StratFactory() {}
    StratFactory(StratFactory&) = delete;
    StratFactory& operator=(StratFactory&) = delete;
    // Добавляет в map стратегию
    bool RegisterStrat(const TypeKey& key, Base* (*Func)()) {
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
        if (stratFactory == nullptr) {
            stratFactory = new FactoryMap;
        }
        return stratFactory;
    }
private:
    typedef std::map <TypeKey, Base*(*)()> FactoryMap;
    static FactoryMap* stratFactory;
};

#endif
