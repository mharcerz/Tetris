//
// Created by mharc on 01.10.2022.
//


#ifndef TETRIS_FIELD_H
#define TETRIS_FIELD_H
enum colors { RED = 1, GREEN, BLUE, YELLOW};

class Field {
private :
    int color;
    struct Posistion {
        int x;
        int y;
    };
protected:
    int virtual set_colors();
public:
    Field(); //set_position
    ~Field();
    Posistion get_Posistion();
    void move_position(int, int);

};


#endif //TETRIS_FIELD_H
