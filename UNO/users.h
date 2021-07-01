#ifndef USERS_H
#define USERS_H


#include "card.h"
#include<random>
#include<chrono>
#include<algorithm>
#include<iostream>
#include<vector>

class users
{
    std::vector<card> player_1;
    std::vector<card> player_2;
    std::vector<card> game_deck;
    std::vector<card> deck;
protected:
public:
    //std::vector<QPushButton*> cards_vector;
    unsigned number_players;
    users() = default;
    users(unsigned);
    unsigned get_num_user();
    void set_num_user(unsigned);
    void two_players();
    std::vector<card> generate_deck();
    std::vector<card>& get_player(unsigned);
    std::vector<card>& get_game_deck();
};

#endif // USERS_H