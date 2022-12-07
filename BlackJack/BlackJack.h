#ifndef BLACK_JACK_H
#define BLACK_JACK_H

#include <vector>
#include <array>

#include "TCard.h"
// #include "StratFactory.h"

class BlackJack {
    public:
    BlackJack();
    BlackJack(size_t numOfPlayers);
    ~BlackJack();

    void DetailedGame();
    void FastGame();
    void TournamentGame();

    void DeckCreate(size_t menuDeck);
    // возвращает количество очков в руке Стратегии
    size_t GetHand(size_t num);
    // возвращает счет Стратегии в турнире
    size_t GetScore(size_t num);

    // очищает руку (для турниров)
    void ClearHand(size_t num);

    private:
    std::array<size_t, 10> deck;
    std::vector<size_t> score;
    std::vector<size_t> hand;
    // TCard card;
    // for (size_t i = 0; i < 10; ++i) {

    // }

};

#endif
