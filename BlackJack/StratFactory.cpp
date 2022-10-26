#include "StratFactory.h"

StratFactory::StratFactory() {
    RegisterStrat("-strat1", CreateStrat1);
    RegisterStrat("-strat2", CreateStrat2);

}

void StratFactory::RegisterStrat(const Key& key, Bot* (*creator)()) {
    Strats[key] = creator;
}
