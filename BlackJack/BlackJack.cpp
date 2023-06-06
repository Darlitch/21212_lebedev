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

void BlackJack::DetailedGame(std::vector<std::string>& strats, size_t player1, size_t player2) {
    bool step = 0;
    AbstractStrategy* strat1 = StratFactory<std::string, AbstractStrategy>::GetInstance()->CreateStrat(strats[player1]);
    AbstractStrategy* strat2 = StratFactory<std::string, AbstractStrategy>::GetInstance()->CreateStrat(strats[player2]);
    TakeCardDetailed(strats, player1);
    TakeCardDetailed(strats, player1);
    TakeCardDetailed(strats, player2);
    TakeCardDetailed(strats, player2);
    while (hand[player1-2] < 21 && hand[player2-2] < 21) {
        step = strat1->Playing(hand[player1-2], 20);
        if (StepDetailed(strats, player1, step)) {
            break;
        }
        step = strat2->Playing(hand[player2-2], 20);
        if (StepDetailed(strats, player2, step)) {
            break;
        }
    }
    PrintWinFastDetailed(strats, player1, player2);
    delete strat1;
    delete strat2;
}

void BlackJack::FastGame(std::vector<std::string> strats, size_t player1, size_t player2) {
    bool step = 0;
    AbstractStrategy* strat1 = StratFactory<std::string, AbstractStrategy>::GetInstance()->CreateStrat(strats[player1]);
    AbstractStrategy* strat2 = StratFactory<std::string, AbstractStrategy>::GetInstance()->CreateStrat(strats[player2]);
    TakeCardFast(player1);
    TakeCardFast(player1);
    TakeCardFast(player2);
    TakeCardFast(player2);
    while (hand[player1-2] < 21 && hand[player2-2] < 21) {
        step = strat1->Playing(hand[player1-2], 20);
        if (StepFast(player1, step)) {
            break;
        }
        step = strat2->Playing(hand[player2-2], 20);
        if (StepFast(player2, step)) {
            break;
        }
    }
    PrintWinFastDetailed(strats, player1, player2);
    delete strat1;
    delete strat2;
}

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

bool BlackJack::TakeCardDetailed(std::vector<std::string>& strats, size_t player) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(queue.begin(), queue.end(), g);
    for (size_t i = 0; i < 10; ++i) {
        if (deck[queue[i]] != 0) {
            std::cout << strats[player] << " take: " << queue[i] << std::endl;
            hand[player-2] += queue[i];
            std::cout << strats[player] << ":" << hand[player-2] << std::endl;
            deck[queue[i]]--;
            return 0;
        }
    }
    return 1;
}

bool BlackJack::StepDetailed(std::vector<std::string>& strats, size_t player, bool step) {
    if (step == 0) {
        std::cout << strats[player] << " passed" << std::endl;
    } else {
        TakeCardDetailed(strats, player);
        if (hand[player-2] > 21) {
            std::cout << strats[player] << " lose!" << std::endl;
            return 1;
        } else if (hand[player-2] == 21) {
            return 1;
        }
    }
    return 0;
}

bool BlackJack::TakeCardFast(size_t player) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(queue.begin(), queue.end(), g);
    for (size_t i = 0; i < 10; ++i) {
        if (deck[queue[i]] != 0) {
            hand[player-2] += queue[i];
            deck[queue[i]]--;
            return 0;
        }
    }
    return 1;
}

bool BlackJack::StepFast(size_t player, bool step) {
    if (step != 0) {
        TakeCardFast(player);
        if (hand[player-2] >= 21) {
            return 1;
        }
    }
    return 0;
}

void BlackJack::PrintWinFastDetailed(std::vector<std::string>& strats, size_t player1, size_t player2) {
    if (hand[player1-2] == 21 || hand[player2-2] == 22) {
        std::cout << strats[player1] << " WIN!!!" << std::endl;
    } else {
        std::cout << strats[player2] << " WIN!!!" << std::endl;
    }
    std::cout << strats[player1] << ":" << hand[player1-2] << std::endl;
    std::cout << strats[player2] << ":" << hand[player2-2] << std::endl;
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