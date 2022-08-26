#ifndef INTER_H_
#define INTER_H_
#include "board.h"

class Inter {
public:
    void insertCharacter(int move, Board& b);
    bool check_if_end(int move, Board& b);
};

#endif