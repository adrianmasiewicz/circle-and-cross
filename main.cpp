#include <iostream>
#include "board.h"
#include "inter.h"
#include "start.h"
using namespace std;

int main() {
    Inter inter;
    system("clear");
    StartSetting(inter);

    do
    {        
        Board board;
        for (int i = 0; !(inter.check_if_end(i, board)); i++) {
            board.show();
            inter.insertCharacter(i, board);
            system("clear");
        }
        board.show();
        inter.showPoints();
        inter.changeFirst();
    } while (inter.stillPlay());
    
}
