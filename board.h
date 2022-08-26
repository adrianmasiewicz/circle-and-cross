#ifndef BOARD_H_
#define BOARD_H_
class Board {
private:
    enum symbol { circe,
                  cross,
                  empty };
    symbol character[9];
public:
    Board();

    bool check_if_win() const;
    bool check_if_win_abc(int a, int b, int c) const;
    bool check_if_empty(int value) const;
    void insert_O(int value);
    void insert_X(int value);
    void computer_insert_O();
    void computer_insert_X();
    void show() const;
};

#endif