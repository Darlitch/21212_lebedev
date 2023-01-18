#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>
#include <vector>

#include "StratFactory.h"

class AbstractStrategy {
public:
    AbstractStrategy() {}
    ~AbstractStrategy() {}
    virtual void Playing() {}
private:
};

class Strat1 : public AbstractStrategy {
public:
    Strat1() {}
    ~Strat1() {}
    void Playing() {
        std::cout << "Strat1" << std::endl;
    }
    static AbstractStrategy* CreateStrat1() {
        return new Strat1;
    }
    static const bool Reg() {
        return StratFactory<std::string, Strat1*(*)()>::GetInstance()->
            RegisterStrat("-strat1", Strat1::CreateStrat1);// вызов фабрики ->регистрация ;

    }
    static const bool strat1 = Strat1::Reg();
};

class Strat2 : public AbstractStrategy {
public:
    Strat2() {}
    ~Strat2() {}

    void Playing() {
        std::cout << "Strat2" << std::endl;
    }
};

namespace {
    AbstractStrategy* CreateStrat2() {
        return new Strat2;
    }
    bool Reg() {
        return StratFactory<std::string, AbstractStrategy*(*)()>::GetInstance()->
            RegisterStrat("-strat2", CreateStrat2);// вызов фабрики ->регистрация ;

    }
    const bool strat2 = Reg();
}

class Strat3 : public AbstractStrategy {
public:
    Strat3() {}
    ~Strat3() {}
    void Playing() {
        std::cout << "Strat3" << std::endl;
    }
    static AbstractStrategy* CreateStrat3() {
        return new Strat3;
    }
    static bool Reg() {
        return StratFactory<std::string, Strat3*(*)()>::GetInstance()->
            RegisterStrat("-strat3", Strat3::CreateStrat3);// вызов фабрики ->регистрация ;

    }
    static const bool strat3 = Strat3::Reg();
};

class StratCfg : public AbstractStrategy {
public:
    StratCfg() {}
    ~StratCfg() {}
    void Playing() {
        std::cout << "StratCfg" << std::endl;
    }
    static AbstractStrategy* CreateStratCfg() {
        return new StratCfg;
    }
    static bool Reg() {
        return StratFactory<std::string, StratCfg*(*)()>::GetInstance()->
            RegisterStrat("-stratcfg", StratCfg::CreateStratCfg);// вызов фабрики ->регистрация ;

    }
    static const bool stratCfg = StratCfg::Reg();
};

#endif
