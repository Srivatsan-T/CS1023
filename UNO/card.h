#ifndef CARD_H
#define CARD_H


#include <vector>
#include <iostream>
#include <string>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

enum class color_t
{
    RED,
    BLUE,
    GREEN,
    YELLOW,
    NO_COLOR
};

enum class number_t
{
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    SKIP,
    REVERSE,
    DRAW_TWO,
    WILD,
    DRAW_FOUR_WILD,
    NO_NUMBER
};
class card
{
    color_t color;
    number_t number;

public:
    bool power;
    card(color_t c, number_t n);
    card();
    card(const card &);
    color_t get_color();
    number_t get_number();
    void show_card();
    std::string get_color_string();
    std::string get_number_string();
    void color_change(int,std::string);
};

#endif // CARD_H