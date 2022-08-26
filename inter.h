#ifndef INTER_H_
#define INTER_H_
#include "board.h"

class Inter {
private:
    enum symbol {
        circle,
        cross
    };

    enum who_move {
        man,
        computer
    };

    symbol firstSymbol = circle;
    who_move firstMove = man;

public:
    void start();
    void show_start_map();
    void insertCharacter(int nr_move, Board& b);
    bool check_if_end(int nr_move, Board& b);
};

#endif