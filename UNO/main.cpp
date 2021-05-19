#include<iostream>
#include"game.h"

int main()
{
    game g(2);
    g.start_game();
    while(true)
    {
        g.play_game(1);
        g.play_game(2);
    }
    return 0;
}