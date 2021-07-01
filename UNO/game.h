#ifndef GAME_H
#define GAME_H

#include "users.h"
#include "card.h"
#include<vector>
#include<string>
#include<stdlib.h>
class game
{
    public:
    bool is_valid_move;
    bool is_first_move;
    bool win1;
    bool win2;
    game(unsigned);
    users *h;
    void start_game();
    void play_game(unsigned);
    void player_drop(unsigned);
    void player_add(unsigned);
    bool card_drop(unsigned,unsigned);
    bool is_move_available(unsigned );
    void show_player(unsigned);
    void show_last();
    color_t get_color_change();
};


#endif