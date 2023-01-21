#include <iostream>
#include <limits>
#include <cstring>
#include <algorithm>

#include "Strategy.h"
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

    size_t MenuDeck() {
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

    void MenuDetails(int argc, char* argv[], std::vector<std::string>& strats) {
        for (int i = 1; i < argc; ++i) {
            std::string currArgv(argv[i]);
            if (currArgv.find("--mode=") != std::string::npos) {
                strats[0].clear();
                strats[0].append(argv[i]+7);  
            } else if (currArgv.find("--configs=") != std::string::npos) {
                strats[1].clear();
                strats[1].append(argv[i]+10);  
            } else {
                strats.push_back(argv[i]);
            }
        }
    }

    int CheckInput(std::vector<std::string>& strats) {
        if ((strats[0] == "detailed" || strats[0] == "fast") && strats.size() != 4) {
            return 1;
        } else if (strats[0] == "tournament" && (strats.size() > 12 || strats.size() < 4)) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main(int argc, char* argv[]) {
    size_t numOfPlayers = 0;
    std::vector<std::string> strats = {"detailed", "0"};
    MenuDetails(argc, argv, strats);
    if (CheckInput(strats)) {
        std::cout << "Bad arguments" << std::endl;
        return 0;
    }
    numOfPlayers = strats.size()-2;
    size_t menuDeck = MenuDeck();
    // Добавить проверки на большие буквы начальние и т.д.

    BlackJack game(numOfPlayers);  
    game.DeckCreate(menuDeck); 
    if (strats[0] == "detailed") {
        game.DetailedGame(strats);
    // } else if (strats[0] == "fast") {
    //     game.FastGame(strats);
    // } else {
    //     game.TournamentGame(strats);
    }
    return 0;
}