#include "inter.h"
#include <iostream>
using namespace std;

void Inter::start() {
    int choice;

    cout << "Who start?\n"
         << "1 - circle\n"
         << "2 - cross\n";
    cin >> choice;
    if (choice == 1) {
        cout << "Start with a circle!\n";
        firstSymbol = circle;
    } else if (choice == 2) {
        cout << "Start with a cross!\n";
        firstSymbol = cross;
    } else {
        cout << "Incorrect selection!\n"
             << "Start with a circle!\n";
        firstSymbol = circle;
    }
    // show_start_map();
    char x = 'n';
    while (x != 'Y') {
        cout << "Are you ready? [Y/n]";
        cin >> x;
    }
    system("clear");
}

void Inter::show_start_map() {
    int horizontalBar = 13;

    for (int i = 0; i < horizontalBar; i++)
        cout << "—";
    cout << endl;

    for (int i = 0; i < 9; i++) {
        cout << "| " << i + 1 << " ";
        if (i % 3 == 2) {
            cout << "|";
            cout << endl;
        }
    }

    for (int i = 0; i < horizontalBar; i++)
        cout << "—";
    cout << endl;
}

void Inter::insertCharacter(int nr_move, Board& board) {
    int choice;
    if (nr_move % 2 == firstMove) {
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
    }

    if (nr_move % 2 == firstSymbol) {
        board.insert_O(choice);
        cout << "computer thinking...\n";
        // board.computer_insert_O();
    } else {
        // board.insert_X(choice);
        cout << "computer thinking...\n";
        board.computer_insert_X();
    }
}

bool Inter::check_if_end(int nr_move, Board& board) {
    if (!(nr_move < 9)) {
        cout << "DRAW!\n";
        return true;
    }

    nr_move--;
    if (board.check_if_win()) {
        cout << "FINISH for : ";
        if (nr_move % 2 == firstSymbol) {
            cout << "O !\n";
        } else
            cout << "X !\n";

        return true;
    } else {
        return false;
    }
}
