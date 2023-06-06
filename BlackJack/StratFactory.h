#ifndef STRAT_FACTORY_H
#define STRAT_FACTORY_H

#include <map>
#include <iostream>

template <class TypeKey, class Base, class ProductType = Base *(*)()>
class StratFactory {
public:
    ~StratFactory() {
    }
    StratFactory(StratFactory&) = delete;
    StratFactory& operator=(StratFactory&) = delete;
    // Добавляет в map стратегию
    bool RegisterStrat(const TypeKey& key, ProductType Func) {
        std::cout << key;
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
            std::cout << "2222222222";
            return it->second();
        }
        return 0;
    }
    static StratFactory* GetInstance() {
        std::cout << "GET INSTANCE" << std::endl;
        if (factory == nullptr) {
                    std::cout << "GET INSTANCE  111" << std::endl;

            factory = new StratFactory<TypeKey, Base, ProductType>;
        }
        return factory;
    }
private:
    StratFactory() {
        std::cout << "STRAT FACTORY CTOR" <<std::endl;
    }
    static StratFactory<TypeKey, Base, ProductType>* factory;
    typedef std::map <TypeKey, ProductType> FactoryMap;
    FactoryMap stratFactory;
};

template <class TypeKey, class Base, class ProductType>
StratFactory<TypeKey, Base, ProductType>* StratFactory<TypeKey, Base, ProductType>::factory = nullptr;

#endif
