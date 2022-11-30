#include <iostream>

#include "BlackJack.h"

BlackJack::BlackJack() {
    deck.reserve(10);
    score.reserve(2);
    hand.reserve(2);
}

BlackJack::BlackJack(size_t numOfPlayers) {
    deck.reserve(10);
    score.reserve(numOfPlayers);
    hand.reserve(numOfPlayers);
}

// BlackJack::BlackJack()

// int BlackJack::Menu() {
//     size_t m = 0, menuDeck = 0;
//     std::cout << "Select card issuance:\n1. Simplified mode: random number from 1 to 10.\n2. Decks\n";
//     while (m != 1 && m != 2) {
//         std::cin >> m;
//         switch(m) {
//             case 1:
//                 menuDeck = 0;
//             case 2:
//                 menuDeck = NumOfDeck();
//             default:
//                 std::cout << "Incorrect card issuance mode\n";
//         }
//     }
// }

// int NumOfDeck() {
//     std::cout << "Enter the number of decks:\n";
//     int numOfDeck = 0;
//     while (numOfDeck < 0 || numOfDeck > 200) {
//         std::cin >> numOfDeck;
//         if (numOfDeck < 0 || numOfDeck > 200) {
//             std::cout << "Incorrect number of decks\n";
//         }
//     }
//     return numOfDeck;
// }

void BlackJack::SimpleGame() {
    deck.reserve(10);
    for (int i = 0; i < 10; ++i) {

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