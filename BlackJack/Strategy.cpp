#include "Strategy.h"
#include <printf.h>

bool Strat1::Playing(size_t lastScore, size_t scoreEnemy) {
    if (lastScore < scoreEnemy || lastScore < 16) {
        return 1;
    } else {
        return 0;
    }
}

//namespace {
    AbstractStrategy* CreateStrat1() {
        return new Strat1;
    }
    // bool Reg() {
    //     printf("22222222");
    //     return StratFactory<std::string, AbstractStrategy, AbstractStrategy*(*)()>::GetInstance()->
    //         RegisterStrat("strat1", CreateStrat1);// вызов фабрики ->регистрация ;

    // }
    // const bool strat_1 = Reg();
    bool a = StratFactory<std::string, AbstractStrategy>::GetInstance()->
            RegisterStrat("strat1", CreateStrat1);
    // printf("%b", strat_1);
//}

bool Strat2::Playing(size_t lastScore, size_t scoreEnemy) {
    if (lastScore < scoreEnemy || lastScore < 20) {
        return 1;
    } else {
        return 0;
    }
}

namespace {
    AbstractStrategy* CreateStrat2() {
        return new Strat2;
    }
    // bool Reg2() {
    //     return StratFactory<std::string, AbstractStrategy>::GetInstance()->
    //         RegisterStrat("strat2", CreateStrat2);// вызов фабрики ->регистрация ;

    // }
    // const bool strat2 = Reg2();
    bool b = StratFactory<std::string, AbstractStrategy>::GetInstance()->
            RegisterStrat("strat2", CreateStrat2);
}

// bool Strat3::Playing(size_t lastScore, size_t scoreEnemy) {
//     if (lastScore < 16) {
//         return 1;
//     } else {
//         return 0;
//     }
// }

// namespace {
//     static AbstractStrategy* CreateStrat3() {
//         return new Strat3;
//     }
//     static bool Reg3() {
//         return StratFactory<std::string, AbstractStrategy>::GetInstance()->
//             RegisterStrat("-strat3", CreateStrat3);// вызов фабрики ->регистрация ;

//     }
//     bool strat3 = Reg3();
// }

// bool StratCfg::Playing(size_t lastScore, size_t scoreEnemy) {
//     if (lastScore < 16) {
//         return 1;
//     } else {
//         return 0;
//     }
// }

// namespace {
//     AbstractStrategy* CreateStratCfg() {
//         return new StratCfg;
//     }
//     bool RegCfg() {
//         return StratFactory<std::string, AbstractStrategy>::GetInstance()->
//             RegisterStrat("-stratcfg", CreateStratCfg);// вызов фабрики ->регистрация ;

//     }
//      bool stratCfg = RegCfg();
// }
