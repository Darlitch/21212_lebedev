#include <iostream>
#include <algorithm>
#include <random>

#include "BlackJack.h"
#include "StratFactory.h"

BlackJack::BlackJack(size_t numOfPlayers) {
    score.reserve(numOfPlayers);
    hand.reserve(numOfPlayers);
}

BlackJack::~BlackJack() {
}

void BlackJack::DetailedGame(std::vector<std::string> strats) {
    size_t card1, card2 = 0;
    AbstractStrategy* strat1 = StratFactory<std::string, AbstractStrategy>::GetInstance()->CreateStrat(strats[2]);
    AbstractStrategy* strat2 = StratFactory<std::string, AbstractStrategy>::GetInstance()->CreateStrat(strats[3]);
    card1 = TakeCard();
    card2 = TakeCard();
    std::cout << strats[2] << " take: " << card1 << " and " << card2 << std::endl;
    hand[0] += card1 + card2;
    std::cout << strats[2] << ":" << hand[0] << std::endl;
    card1 = TakeCard();
    card2 = TakeCard();
    std::cout << strats[3] << " take: " << card1 << " and " << card2 << std::endl;
    hand[1] += card1 + card2;
    std::cout << strats[3] << ":" << hand[1] << std::endl;
    while (score[0] < 21 && score[1] < 21) {

    }
}

// void BlackJack::FastGame(std::vector<std::string> strats) {

// }

// void BlackJack::TournamentGame(std::vector<std::string> strats) {

// }

void BlackJack::DeckCreate(size_t numOfDecks) {
    if (numOfDecks == 0) {
        for (size_t i = 0; i < 10; ++i) {
            deck[i] = 1000;
        }
    } else {
        for (size_t i = 0; i < 9; ++i) {
            deck[i] = 4 * numOfDecks;
        }
        deck[9] = 16 * numOfDecks;
    }
    for (size_t i = 0; i < 10; ++i) {
        queue[i] = i;
    }
}

size_t BlackJack::TakeCard() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(queue.begin(), queue.end(), g);
    for (size_t i = 0; i < 10; ++i) {
        if (deck[queue[i]] != 0) {
            return queue[i] + 1;
        }
    }
    return 0;
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