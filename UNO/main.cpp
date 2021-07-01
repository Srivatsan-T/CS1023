#include <iostream>
#include "game.h"

int main()
{
    game g(2);
    g.start_game();
    while (g.win1 == false && g.win2 == false)
    {
        g.play_game(1);
        std::cout << "**************************" << std::endl;
        std::cout << "END OF A MOVE" << std::endl;
        std::cout << "**************************" << std::endl;
        g.play_game(2);
        std::cout << "**************************" << std::endl;
        std::cout << "END OF A MOVE" << std::endl;
        std::cout << "**************************" << std::endl;
    }
    if (g.win1 == true)
    {
        std::cout << "Player 1 won" << std::endl;
    }
    else if (g.win2 == true)
    {
        std::cout << "Player 2 won" << std::endl;
    }
    return 0;
}