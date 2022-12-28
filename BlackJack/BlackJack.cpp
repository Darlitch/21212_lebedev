#include <iostream>

#include "BlackJack.h"
#include "StratFactory.h"

BlackJack::BlackJack(size_t numOfPlayers) {
    stratFact.RegisterStrat("Strat1", CreateStrat1);
    stratFact.RegisterStrat("Strat2", CreateStrat2);
    stratFact.RegisterStrat("Strat3", CreateStrat3);
    stratFact.RegisterStrat("StratCfg", CreateStratCfg);
    score.reserve(numOfPlayers);
    hand.reserve(numOfPlayers);
}

BlackJack::~BlackJack() {
}

void BlackJack::DetailedGame(std::vector<std::string> strats) {
    AbstractStrategy* strat1 = stratFact.CreateStrat(strats[2]);
    AbstractStrategy* strat2 = stratFact.CreateStrat(strats[4]);
}

void BlackJack::DeckCreate(size_t numOfDecks) {
    if (numOfDecks == 0) {
        for (auto& i: deck) {
            deck[i] = 1000;
        }
    } else {
        for (int i = 0; i < 8; ++i) {
            deck[i] = 4 * numOfDecks;
        }
        deck[9] = 16 * numOfDecks;
    }
}

size_t BlackJack::GetHand(size_t num) {
    return hand.at(num);
}

size_t BlackJack::GetScore(size_t num) {
    return score.at(num);
}

void BlackJack::ClearHand(size_t num) {
    hand.at(num) = 0;
}