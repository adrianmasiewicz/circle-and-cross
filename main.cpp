#include <iostream>
#include "board.h"
#include "inter.h"
using namespace std;

int main() {
    Board board;
    Inter inter;
    system("clear");

    //inter.start();
    for (int i = 0; !(inter.check_if_end(i, board)); i++) {
        board.show();
        inter.insertCharacter(i, board);
        system("clear");
    }
    board.show();
}
