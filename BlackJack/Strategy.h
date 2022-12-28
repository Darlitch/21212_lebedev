#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>

class AbstractStrategy {
public:
    AbstractStrategy() {}
    virtual ~AbstractStrategy() {}
private:
};

class Strat1 : public AbstractStrategy {
    Strat1() {}
    ~Strat1() {}
};

class Strat2 : public AbstractStrategy {
    Strat2() {}
    ~Strat2() {}
};

class Strat3 : public AbstractStrategy {
    Strat3() {}
    ~Strat3() {}
};

class StratCfg : public AbstractStrategy {
    StratCfg() {}
    ~StratCfg() {}
};

#endif
