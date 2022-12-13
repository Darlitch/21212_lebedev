#include "StratFactory.h"

// StratFactory::StratFactory() {
//     RegisterStrat("-strat1", CreateStrat1);
//     RegisterStrat("-strat2", CreateStrat2);
// }

// void StratFactory::RegisterStrat(const std::string& key, Bot* (*creator)()) {
//     Strats[key] = creator;
// }
template <class S>
void StratFactory::RegisterStrat(const std::string& key) {
    typename FactoryMap::iterator it = stratFactory.find(key);
    if (it == stratFactory.end()) {
        stratFactory[key] = new ?;
    }
}

Strat* StratFactory::CreateStrat(const std::string& key) {
    typename FactoryMap::iterator it = stratFactory.find(key);
    if (it != stratFactory.end()) {
        return it->second->create();
    }
    return 0;
}
