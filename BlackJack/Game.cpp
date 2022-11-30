#include <iostream>
#include <limits>

#include "BlackJack.h"

namespace {
    int NumOfDeck() {
        std::cout << "Enter the number of decks:" << std::endl;
        int numOfDeck = 0;
        while (numOfDeck < 1 || numOfDeck > 200) {
            std::cin >> numOfDeck;
            if (std::cin.fail() || numOfDeck < 1 || numOfDeck > 200) {
                std::cout << "Incorrect number of decks" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        return numOfDeck;
    }

    int Menu() {
        int m = 0, menuDeck = 0;
        std::cout << "Select card issuance:\n1. Simplified mode: random number from 1 to 10.\n2. Decks" << std::endl;
        while (m != 1 && m != 2) {
            std::cin >> m;
            if (std::cin.fail() || (m != 1 && m != 2)) {
                std::cout << "Incorrect card issuance mode" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            switch(m) {
                case 1:
                    menuDeck = 0;
                    break;
                case 2:
                    menuDeck = NumOfDeck();
                    break;
                default:
                    break;
            }
        }
        return menuDeck;
    }
}

int main() {
    int menuDeck = Menu();
    std::cout << menuDeck;
}