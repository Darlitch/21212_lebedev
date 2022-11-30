#ifndef BLACK_JACK_H
#define BLACK_JACK_H

#include <vector>

#include "TCard.h"
// #include "StratFactory.h"

class BlackJack {
    public:
    BlackJack();
    BlackJack(size_t numOfPlayers);
    ~BlackJack();
    // int Menu();
    // int NumOfDeck();

    void SimpleGame();
    void CardGame(int n);
    // возвращает количество очков в руке Стратегии
    size_t GetHand(size_t num);
    // возвращает счет Стратегии в турнире
    size_t GetScore(size_t num);

    // очищает руку (для турниров)
    void ClearHand(size_t num);

    private:
    std::vector<size_t> deck;
    std::vector<size_t> score;
    std::vector<size_t> hand;
    // TCard card;
    // for (size_t i = 0; i < 10; ++i) {

    // }

};

#endif
