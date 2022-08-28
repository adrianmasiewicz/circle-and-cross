#include "inter.h"
#include <iostream>
using namespace std;

void Inter::showPoints() const {
    cout << "Circle: " << getCirclePoints() << " | ";
    cout << "Cross:" << getCrossPoints() << "\n";
}

bool Inter::stillPlay() const {
    char c;

    if ((getMaxPoints() <= getCirclePoints()) ||
        (getMaxPoints() <= getCrossPoints())) {
        return false;
    }

    cout << "Are we still play? [Y/n]: ";
    cin >> c;
    if (c == 'Y' || c == 'y') {
        system("clear");
        return true;
    } else
        return false;
}

void Inter::changeFirst() {
    if (firstMove == man) {
        firstMove = computer;
    } else {
        firstMove = man;
    }

    if (firstSymbol == circle) {
        firstSymbol = cross;
    } else {
        firstSymbol = circle;
    }
}

void Inter::insertCharacter(int nr_move, Board& board) {
    int choice;
    if (nr_move % 2 == firstMove) {
        bool loop;
        do {
            loop = false;
            cout << "Enter the place where you want to insert a character ";
            if (mapVersion == original) {
                cout << "(original number map): ";
                cin >> choice;
                choice--;

            } else {
                cout << "(Num Lock number map): ";
                cin >> choice;

                switch (choice) {
                case 7:
                    choice = 0;
                    break;
                case 8:
                    choice = 1;
                    break;
                case 9:
                    choice = 2;
                    break;
                case 4:
                    choice = 3;
                    break;
                case 5:
                    choice = 4;
                    break;
                case 6:
                    choice = 5;
                    break;
                case 1:
                    choice = 6;
                    break;
                case 2:
                    choice = 7;
                    break;
                case 3:
                    choice = 8;
                    break;
                default:
                    break;
                }
            }

            if (!board.check_if_empty(choice)) {
                cout << "This place is already taken!";
                loop = true;
            }

        } while (loop);
    }

    if ((firstMove == man && firstSymbol == cross) ||
        (firstMove == computer && firstSymbol == circle)) {
        if (nr_move % 2 == firstSymbol) {
            board.computer_insert_O();
        } else {
            board.insert_X(choice);
        }
    }

    if ((firstMove == man && firstSymbol == circle) ||
        (firstMove == computer && firstSymbol == cross)) {
        if (nr_move % 2 == firstSymbol) {
            board.insert_O(choice);
            cout << "computer thinking...\n";
        } else {
            cout << "computer thinking...\n";
            board.computer_insert_X();
        }
    }
}

bool Inter::check_if_end(int nr_move, Board& board) {
    if (board.check_if_win()) {
        cout << "FINISH for : ";
        if (nr_move % 2 != firstSymbol) {
            cout << "Circle !\n";
            circlePoints++;
        } else {
            cout << "Cross !\n";
            crossPoints++;
        }
        return true;
    }

    if (nr_move >= 9) {
        cout << "DRAW!\n";
        return true;
    }

    return false;
}

int Inter::getMaxPoints() const {
    return maxPoints;
}

int Inter::getCirclePoints() const {
    return circlePoints;
}

int Inter::getCrossPoints() const {
    return crossPoints;
}

int Inter::getFirstMove() const {
    return firstMove;
}
int Inter::getFirstSymbol() const {
    return firstSymbol;
}
int Inter::getMapVersion() const {
    return mapVersion;
}

void Inter::setMaxPoints(int points) {
    maxPoints = points;
}

void Inter::setMapVersion(map m) {
    mapVersion = m;
}
void Inter::setFirstSymbol(symbol s) {
    firstSymbol = s;
}
void Inter::setFirstMove(who_move w_m) {
    firstMove = w_m;
}