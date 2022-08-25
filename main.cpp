#include <iostream>
#include "board.h"

using namespace std;

void insertCharacter(int move, Board& b);
bool check_if_end(int move, Board& b);

int main() {
    system("clear");
    Board board;

    for (int i = 0; !(check_if_end(i, board)); i++) {
        board.show();
        insertCharacter(i, board);
        system("clear");
    }
    board.show();
}

void insertCharacter(int move, Board& board) {
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

bool check_if_end(int move, Board& board) {
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