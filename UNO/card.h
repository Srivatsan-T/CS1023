#ifndef CARD_H
#define CARD_H

#define SKIP 11
#define REVERSE 12
#define DRAW_TWO 13
#define WILD 14
#define DRAW_FOUR_WILD 15
#define RED 0
#define BLUE 1
#define GREEN 2
#define YELLOW 3
#define NO_COLOR 5


#include<vector>
#include<iostream>
#include<string>

class card
{
    unsigned color;
    unsigned number;
public:
    card(unsigned,unsigned);
    card();
    card(const card&);
    unsigned get_color();
    unsigned get_number();
    void set_color(unsigned);
    void set_number(unsigned);
    void show_card();

};

#endif // CARD_H