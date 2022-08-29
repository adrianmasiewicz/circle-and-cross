#ifndef START_H_
#define START_H_

#include <iostream>
#include "inter.h"

using namespace std;

enum map {
    original,
    numLock
};

void show_start_map(map m1);
void who_first(Inter& inter);
void StartSetting(Inter& inter);
void yourSign(Inter& inter);
void numberMap(Inter& inter);
void maxPoints(Inter& inter);

void StartSetting(Inter& inter) {
    char choice;
    char saveChanges;
    cout << "press 'p' to play or 'q' to enter the settings:\n";
    cin >> choice;
    if (choice == 'q') {
        who_first(inter);
        yourSign(inter);
        numberMap(inter);
        maxPoints(inter);

        cout << "Save changes? [Y/n]: ";
        cin >> saveChanges;
        if (saveChanges == 'Y' || saveChanges == 'y') {
            inter.saveChanges();
        }
    }
    system("clear");
}

void show_start_map(map m1) {
    int horizontalBar = 13;

    for (int i = 0; i < horizontalBar; i++)
        cout << "—";
    cout << endl;

    if (m1 == original) {
        for (int i = 0; i < 9; i++) {
            cout << "| " << i + 1 << " ";
            if (i % 3 == 2) {
                cout << "|";
                cout << endl;
            }
        }
    }
    if (m1 == numLock) {
        int sing[9] = {7, 8, 9, 6, 5, 4, 3, 2, 1};
        for (int i = 0; i < 9; i++) {
            cout << "| " << sing[i] << " ";
            if (i % 3 == 2) {
                cout << "|";
                cout << endl;
            }
        }
    }

    for (int i = 0; i < horizontalBar; i++)
        cout << "—";
    cout << endl;
}

void who_first(Inter& inter) {
    char choice;
    cout << "Who first?\n"
         << "1 - You\n"
         << "2 - computer\n";
    cin >> choice;

    if (choice == '1') {
        cout << "You start!\n";
        inter.setFirstMove(inter.man);
    } else if (choice == '2') {
        cout << "Computer start!\n";
        inter.setFirstMove(inter.computer);
    } else {
        cout << "Incorrect selection!\n"
             << "You start!\n";
        inter.setFirstMove(inter.man);
    }
}

void yourSign(Inter& inter) {
    char choice;
    cout << "Choose your sing?\n"
         << "1 - circle\n"
         << "2 - cross\n";
    cin >> choice;

    if (inter.getFirstMove() == inter.man) {
        if (choice == '1') {
            cout << "You are circle!\n";
            inter.setFirstSymbol(inter.circle);
        } else if (choice == '2') {
            cout << "You are cross!\n";
            inter.setFirstSymbol(inter.cross);
        } else {
            cout << "Incorrect selection!\n"
                 << "You are circle!\n";
            inter.setFirstSymbol(inter.circle);
        }
    }

    if (inter.getFirstMove() == inter.computer) {
        if (choice == '1') {
            cout << "You are circle!\n";
            inter.setFirstSymbol(inter.cross);
        } else if (choice == '2') {
            cout << "You are cross!\n";
            inter.setFirstSymbol(inter.circle);
        } else {
            cout << "Incorrect selection!\n"
                 << "You are circle!\n";
            inter.setFirstSymbol(inter.cross);
        }
    }
}
void numberMap(Inter& inter) {
    char choice;
    cout << "Choose number map\n"
         << "1 - original: \n";
    show_start_map(original);
    cout << "2 - Num Lock: \n";
    show_start_map(numLock);
    cin >> choice;
    if (choice == 1) {
        cout << "You play with original map.\n";
        inter.setMapVersion(inter.original);
    } else {
        cout << "You play with Num Lock map.\n";
        inter.setMapVersion(inter.numLock);
    }
}

void maxPoints(Inter& inter) {
    int points;
    cout << "How many points are we playing to: ";
    cin >> points;
    inter.setMaxPoints(points);
}

#endif