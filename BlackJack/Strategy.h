#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>

#include "Strategy.h"

class AbstractStrategy {
public:
    AbstractStrategy() {}
    virtual ~AbstractStrategy() {}
private:
};

class Strat1 : public AbstractStrategy {
public:
    Strat1() {}
    ~Strat1() {}
    static AbstractStrategy* CreateStrat1() {
        return new Strat1;
    }
};

const bool strat1 = StratFactory<std::string, Strat1*(*)()>::GetInstance()->RegisterStrat("-strat1", Strat1::CreateStrat1);

class Strat2 : public AbstractStrategy {
public:
    Strat2() {}
    ~Strat2() override;
    static AbstractStrategy* CreateStrat2() {
        return new Strat2;
    }
};

class Strat3 : public AbstractStrategy {
public:
    Strat3() {}
    ~Strat3() override;
    static AbstractStrategy* CreateStrat3() {
        return new Strat3;
    }
};

class StratCfg : public AbstractStrategy {
public:
    StratCfg() {}
    ~StratCfg() override;
    static AbstractStrategy* CreateStratCfg() {
        return new StratCfg;
    }
};

#endif
