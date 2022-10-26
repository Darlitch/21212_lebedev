#ifndef BLACK_JACK_H
#define BLACK_JACK_H

#include <iostream>
#include <list>


struct TCard {
    size_t Value = 0;
    size_t Count = 0;
};

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
