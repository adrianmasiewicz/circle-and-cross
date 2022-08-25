#include "board.h"
#include <iostream>

Board::Board() {
    for (int i = 0; i < 9; i++) {
        character[i] = empty;
    }
}

bool Board::check_if_empty(int value) const {
    if (character[value - 1] == empty)
        return true;
    else
        return false;
}
bool Board::check_if_win_abc(int a, int b, int c) const {
    if (character[a] != empty &&
        character[a] == character[b] &&
        character[b] == character[c])
        return true;
    else
        return false;
}

bool Board::check_if_win() const {
    if (check_if_win_abc(0, 1, 2))
        return true;
    if (check_if_win_abc(3, 4, 5))
        return true;
    if (check_if_win_abc(6, 7, 8))
        return true;
    if (check_if_win_abc(0, 3, 6))
        return true;
    if (check_if_win_abc(1, 4, 5))
        return true;
    if (check_if_win_abc(2, 5, 8))
        return true;
    if (check_if_win_abc(0, 4, 5))
        return true;
    if (check_if_win_abc(2, 4, 6))
        return true;

    return false;
}

void Board::insert_X(int value) {
    character[value - 1] = cross;
}

void Board::insert_O(int value) {
    character[value - 1] = circe;
}

void Board::show() const {
    using std::cout;
    using std::endl;
    int horizontalBar = 13;

    for (int i = 0; i < horizontalBar; i++)
        cout << "—";
    cout << endl;

    for (int i = 0; i < 9; i++) {
        cout << "|";

        if (character[i] == empty) {
            cout << " · ";
        } else if (character[i] == circe) {
            cout << " O ";
        } else if (character[i] == cross) {
            cout << " X ";
        } else {
            cout << "ERROR 001";
        }

        if (i % 3 == 2) {
            cout << "|";
            cout << endl;
        }
    }
    for (int i = 0; i < horizontalBar; i++)
        cout << "—";
    cout << endl;
}