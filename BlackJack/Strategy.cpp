#include "Strategy.h"

Strategy::Strategy(Key key) : key(key) {}

size_t Strategy::GetHand() {
    return hand;
}

size_t Strategy::GetScore() {
    return score;
}

void Strategy::ClearHand() {
    score = 0;
}