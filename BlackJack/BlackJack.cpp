#include <iostream>

#include "BlackJack.h"

BlackJack::BlackJack() {
    score.reserve(2);
    hand.reserve(2);
}

BlackJack::BlackJack(size_t numOfPlayers) {
    score.reserve(numOfPlayers);
    hand.reserve(numOfPlayers);
}

BlackJack::~BlackJack() {
}

void BlackJack::DetailedGame(std::vector<std::string> strats) {
    
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