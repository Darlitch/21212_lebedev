#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>
#include <vector>

#include "StratFactory.h"

class AbstractStrategy {
public:
    AbstractStrategy() {}
    virtual ~AbstractStrategy() {}
    virtual bool Playing(size_t lastScore, size_t scoreEnemy) = 0;
private:
};

class Strat1 : public AbstractStrategy {
public:
    Strat1() {}
    ~Strat1() = default;
    bool Playing(size_t lastScore, size_t scoreEnemy);
};

class Strat2 : public AbstractStrategy {
public:
    Strat2() {}
    ~Strat2() = default;
    bool Playing(size_t lastScore, size_t scoreEnemy);
};

// class Strat3 : public AbstractStrategy {
// public:
//     Strat3() {}
//     ~Strat3() = default;
//     bool Playing(size_t lastScore, size_t scoreEnemy);
// };

// class StratCfg : public AbstractStrategy {
// public:
//     StratCfg() {}
//     ~StratCfg() = default;
//     bool Playing(size_t lastScore, size_t scoreEnemy);
// };

#endif
