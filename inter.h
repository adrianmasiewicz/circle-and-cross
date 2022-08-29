#ifndef INTER_H_
#define INTER_H_
#include "board.h"

class Inter {
public:
    enum symbol {
        circle,
        cross
    };

    enum who_move {
        man,
        computer
    };

    enum map {
        original,
        numLock
    };

private:
    int maxPoints = 3;
    int circlePoints = 0;
    int crossPoints = 0;

    map mapVersion = numLock;
    symbol firstSymbol = circle;
    who_move firstMove = man;

public:
    Inter();
    void changeFirst();
    void saveChanges();
    bool stillPlay() const;
    void showPoints() const;
    void insertCharacter(int nr_move, Board& b);
    bool check_if_end(int nr_move, Board& b);

    int getMaxPoints() const;
    int getCirclePoints() const;
    int getCrossPoints() const;
    int getFirstMove() const;
    int getFirstSymbol() const;
    int getMapVersion() const;
    
    void setMaxPoints(int maxPoints);
    void setMapVersion(map);
    void setFirstSymbol(symbol);
    void setFirstMove(who_move); 
};

#endif