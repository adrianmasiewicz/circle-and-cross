#include <iostream>
#include "board.h"
#include "inter.h"
#include "start.h"
using namespace std;

int main() {
    Inter inter;

    system("clear");
    StartSetting(inter);
    /*
        while ((inter.getMaxPoints() > inter.getCirclePoints()) &&
               (inter.getMaxPoints() > inter.getCrossPoints())) {

        }
    */
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
    } while (inter.stillPlay());
    
}
