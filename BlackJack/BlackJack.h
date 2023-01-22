#ifndef BLACK_JACK_H
#define BLACK_JACK_H

#include <vector>
#include <array>

#include "TCard.h"
#include "Strategy.h"

class BlackJack {
    public:
    BlackJack() {}
    BlackJack(size_t numOfPlayers);
    BlackJack(BlackJack&) = delete;
    ~BlackJack();
    BlackJack& operator=(BlackJack&) = delete;

    void DetailedGame(std::vector<std::string>& strats, size_t player1, size_t player2);
    void FastGame(std::vector<std::string> strats, size_t player1, size_t player2);
    // void TournamentGame(std::vector<std::string> strats);

    void DeckCreate(size_t menuDeck);
    bool TakeCardDetailed(std::vector<std::string>& strats, size_t player);
    bool StepDetailed(std::vector<std::string>& strats, size_t player, bool step);

    bool TakeCardFast(size_t player);
    bool StepFast(size_t player, bool step);

    void PrintWinFastDetailed(std::vector<std::string>& strats, size_t player1, size_t player2);
    // возвращает количество очков в руке Стратегии
    size_t GetHand(size_t num);
    // возвращает счет Стратегии в турнире
    size_t GetScore(size_t num);

    // очищает руку (для турниров)
    void ClearHand(size_t num);

    private:
    std::array<size_t, 10> deck;
    std::array<size_t, 10> queue;
    std::vector<size_t> score;
    std::vector<size_t> hand;
};

#endif
