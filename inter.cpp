#include "inter.h"
#include <iostream>
using namespace std;

void Inter::insertCharacter(int move, Board& board){
    int choice;

    bool loop;
    do {
        loop = false;
        cout << "Enter the place where you want to insert a character: ";
        cin >> choice;
        if (!board.check_if_empty(choice)) {
            cout << "This place is already taken!";
            loop = true;
        }
    } while (loop);

    if (move % 2 == 1) {
        board.insert_X(choice);
    } else
        board.insert_O(choice);
}

bool Inter::check_if_end(int move, Board& board){
    if (!(move < 9)) {
        cout << "DRAW!\n";
        return true;
    }

    if (board.check_if_win()) {
        cout << "FINISH!\n";
        return true;
    } else {
        return false;
    }
}


