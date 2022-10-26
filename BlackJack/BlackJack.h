#ifndef BLACK_JACK_H
#define BLACK_JACK_H

#include <list>

#include "StratFactory.h"

class BlackJack {
    public:
    BlackJack();
    BlackJack(size_t n);
    ~BlackJack();

    private:
    std::list<TCard> deck;
    // TCard card;
    // for (size_t i = 0; i < 10; ++i) {

    // }

};

#endif
