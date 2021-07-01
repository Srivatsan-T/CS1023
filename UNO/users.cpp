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
            player_1.emplace_back(deck[i]);
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
        deck.push_back(card(color_t::BLUE, static_cast<number_t>(i) ));
    }
    for(int i=10;i<19;i++)
    {
        deck.push_back(card(color_t::BLUE,static_cast<number_t>(i-9)));
    }
    deck.push_back(card(color_t::BLUE,number_t::SKIP));
    deck.push_back(card(color_t::BLUE,number_t::SKIP));
    deck.push_back(card(color_t::BLUE,number_t::REVERSE));
    deck.push_back(card(color_t::BLUE,number_t::REVERSE));
    deck.push_back(card(color_t::BLUE,number_t::DRAW_TWO));
    deck.push_back(card(color_t::BLUE,number_t::DRAW_TWO));

    for(int i = 0;i<10;i++)
    {
        deck.push_back(card(color_t::RED,static_cast<number_t>(i)));
    }
    for(int i=10;i<19;i++)
    {
        deck.push_back(card(color_t::RED,static_cast<number_t>(i-9)));
    }
    deck.push_back(card(color_t::RED,number_t::SKIP));
    deck.push_back(card(color_t::RED,number_t::SKIP));
    deck.push_back(card(color_t::RED,number_t::REVERSE));
    deck.push_back(card(color_t::RED,number_t::REVERSE));
    deck.push_back(card(color_t::RED,number_t::DRAW_TWO));
    deck.push_back(card(color_t::RED,number_t::DRAW_TWO));

    for(int i = 0;i<10;i++)
    {
        deck.push_back(card(color_t::GREEN,static_cast<number_t>(i)));
    }
    for(int i=10;i<19;i++)
    {
        deck.push_back(card(color_t::GREEN,static_cast<number_t>(i-9)));
    }

    deck.push_back(card(color_t::GREEN,number_t::SKIP));
    deck.push_back(card(color_t::GREEN,number_t::SKIP));
    deck.push_back(card(color_t::GREEN,number_t::REVERSE));
    deck.push_back(card(color_t::GREEN,number_t::REVERSE));
    deck.push_back(card(color_t::GREEN,number_t::DRAW_TWO));
    deck.push_back(card(color_t::GREEN,number_t::DRAW_TWO));

    for(int i = 0;i<10;i++)
    {
        deck.push_back(card(color_t::YELLOW,static_cast<number_t>(i)));
    }
    for(int i=10;i<19;i++)
    {
        deck.push_back(card(color_t::YELLOW,static_cast<number_t>(i-9)));
    }

    deck.push_back(card(color_t::YELLOW,number_t::SKIP));
    deck.push_back(card(color_t::YELLOW,number_t::SKIP));
    deck.push_back(card(color_t::YELLOW,number_t::REVERSE));
    deck.push_back(card(color_t::YELLOW,number_t::REVERSE));
    deck.push_back(card(color_t::YELLOW,number_t::DRAW_TWO));
    deck.push_back(card(color_t::YELLOW,number_t::DRAW_TWO));

    for(int i=100;i<104;i++)
    {
        deck.push_back(card(color_t::NO_COLOR,number_t::WILD));
    }

    for(int i=104;i<108;i++)
    {
        deck.push_back(card(color_t::NO_COLOR,number_t::DRAW_FOUR_WILD));
    }
    for(int i=0;i<108;i++)
    {
        deck[i].power = true;
    }
    return deck;
}

std::vector<card>& users::get_player(unsigned n)
{
    if(n == 1)
    {
        return player_1;
    }
    else if(n == 2)
    {
        return player_2;
    }
}


std::vector<card>& users::get_game_deck()
{
    return game_deck;
}