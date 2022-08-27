#include "board.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "thought.h"

Board::Board() {
    for (int i = 0; i < 9; i++) {
        character[i] = empty;
    }
}

bool Board::check_if_empty(int value) const {
    if (character[value] == empty)
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
    if (check_if_win_abc(1, 4, 7))
        return true;
    if (check_if_win_abc(2, 5, 8))
        return true;
    if (check_if_win_abc(0, 4, 8))
        return true;
    if (check_if_win_abc(2, 4, 6))
        return true;

    return false;
}

void Board::insert_O(int value) {
    character[value - 1] = circe;
}

void Board::insert_X(int value) {
    character[value - 1] = cross;
}

void Board::computer_insert_O() {
    int random;
    Thought(10);
    srand(time(NULL));
    do {
        random = (std::rand() % 9);
    } while (character[random] != empty);
    character[random] = circe;
}

void Board::computer_insert_X() {
    int random;
    Thought(10);
    srand(time(NULL));

    computer_symbol = cross;
    if (computer_check_threat(computer_symbol)) {
        // computer check the threat and insert a character
    } else {
        do {
            random = (std::rand() % 9);
        } while (character[random] != empty);
        character[random] = cross;
    }
}

bool Board::computer_check_threat(symbol computer_symbol) {
    symbol man_symbol;
    if (computer_symbol == circe)
        man_symbol = cross;
    else
        man_symbol = circe;

    for (int i = 0; i < 9; i++) {
        if (check_if_empty(i) &&
            computer_check_threat_2(computer_symbol, i)) {
            character[i] = cross;
            return true;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (check_if_empty(i) &&
            computer_check_threat_2(man_symbol, i)) {
            character[i] = cross;
            return true;
        }
    }

    return false;
}

bool Board::computer_check_threat_2(symbol s, int v) const {
    /*
     0 1 2
     3 4 5
     6 7 8
     */
    if (v == 0) {
        if ((character[1] == s && character[1] == character[2]) ||
            (character[3] == s && character[3] == character[6]) ||
            (character[4] == s && character[4] == character[8])) {
            return true;
        }
    } else if (v == 1) {
        if ((character[0] == s && character[0] == character[2]) ||
            (character[4] == s && character[4] == character[7])) {
            return true;
        }
    } else if (v == 2) {
        if ((character[0] == s && character[0] == character[1]) ||
            (character[4] == s && character[4] == character[6]) ||
            (character[5] == s && character[5] == character[8])) {
            return true;
        }
    } else if (v == 3) {
        if ((character[0] == s && character[0] == character[6]) ||
            (character[4] == s && character[4] == character[5])) {
            return true;
        }
    } else if (v == 4) {
        if ((character[3] == s && character[3] == character[5]) ||
            (character[1] == s && character[1] == character[7]) ||
            (character[1] == s && character[0] == character[8]) ||
            (character[1] == s && character[6] == character[2])) {
            return true;
        }
    } else if (v == 5) {
        if ((character[2] == s && character[2] == character[8]) ||
            (character[3] == s && character[3] == character[4])) {
            return true;
        }
    } else if (v == 6) {
        if ((character[0] == s && character[0] == character[3]) ||
            (character[4] == s && character[4] == character[2]) ||
            (character[7] == s && character[7] == character[8])) {
            return true;
        }
    } else if (v == 7) {
        if ((character[1] == s && character[1] == character[4]) ||
            (character[6] == s && character[6] == character[8])) {
            return true;
        }
    } else if (v == 8) {
        if ((character[0] == s && character[0] == character[4]) ||
            (character[2] == s && character[2] == character[5]) ||
            (character[6] == s && character[6] == character[7])) {
            return true;
        }
    }

    return false;
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
            // cout << " "<<i+1<<" ";
        } else if (character[i] == circe) {
            cout << " O ";
        } else if (character[i] == cross) {
            cout << " X ";
        } else {
            cout << "ERROR";
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