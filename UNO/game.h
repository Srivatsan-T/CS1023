#ifndef GAME_H
#define GAME_H

#include "users.h"
#include "card.h"
#include<vector>
#include<string>

class game
{
    public:
    bool is_valid_move;
    bool is_lose_turn;
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
};


#endif