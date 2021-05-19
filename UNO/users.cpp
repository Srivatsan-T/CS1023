#include "users.h"

users::users(unsigned n)
{
    number_players = n;
}

unsigned users::get_num_user()
{
    return number_players;
}

void users::two_players()
{
    if(number_players == 2)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine e(seed);
        std::shuffle (users::deck.begin(), users::deck.end(),e);
        for(int i=0;i<10;i++)
        {
            player_1.emplace_back(users::deck[i]);
        }

        for(int i=10;i<20;i++)
        {
            player_2.emplace_back(deck[i]);
        }

        for(int i=20;i<108;i++)
        {
            game_deck.emplace_back(deck[i]);
        }
    }
}

std::vector<card> users::generate_deck()
{
    for(int i = 0;i<10;i++)
    {
        deck.push_back(card(BLUE,i));
    }
    for(int i=10;i<19;i++)
    {
        deck.push_back(card(BLUE,i-9));
    }
    deck.push_back(card(BLUE,SKIP));
    deck.push_back(card(BLUE,SKIP));
    deck.push_back(card(BLUE,REVERSE));
    deck.push_back(card(BLUE,REVERSE));
    deck.push_back(card(BLUE,DRAW_TWO));
    deck.push_back(card(BLUE,DRAW_TWO));

    for(int i = 0;i<10;i++)
    {
        deck.push_back(card(RED,i));
    }
    for(int i=10;i<19;i++)
    {
        deck.push_back(card(RED,i-9));
    }
    deck.push_back(card(RED,SKIP));
    deck.push_back(card(RED,SKIP));
    deck.push_back(card(RED,REVERSE));
    deck.push_back(card(RED,REVERSE));
    deck.push_back(card(RED,DRAW_TWO));
    deck.push_back(card(RED,DRAW_TWO));

    for(int i = 0;i<10;i++)
    {
        deck.push_back(card(GREEN,i));
    }
    for(int i=10;i<19;i++)
    {
        deck.push_back(card(GREEN,i-9));
    }

    deck.push_back(card(GREEN,SKIP));
    deck.push_back(card(GREEN,SKIP));
    deck.push_back(card(GREEN,REVERSE));
    deck.push_back(card(GREEN,REVERSE));
    deck.push_back(card(GREEN,DRAW_TWO));
    deck.push_back(card(GREEN,DRAW_TWO));

    for(int i = 0;i<10;i++)
    {
        deck.push_back(card(YELLOW,i));
    }
    for(int i=10;i<19;i++)
    {
        deck.push_back(card(YELLOW,i-9));
    }

    deck.push_back(card(YELLOW,SKIP));
    deck.push_back(card(YELLOW,SKIP));
    deck.push_back(card(YELLOW,REVERSE));
    deck.push_back(card(YELLOW,REVERSE));
    deck.push_back(card(YELLOW,DRAW_TWO));
    deck.push_back(card(YELLOW,DRAW_TWO));

    for(int i=100;i<104;i++)
    {
        deck.push_back(card(NO_COLOR,WILD));
    }

    for(int i=104;i<108;i++)
    {
        deck.push_back(card(NO_COLOR,DRAW_FOUR_WILD));
    }
    return deck;
}

std::vector<card>& users::get_player1()
{
    return player_1;
}

std::vector<card>& users::get_player2()
{
    return player_2;
}

std::vector<card>& users::get_game_deck()
{
    return game_deck;
}