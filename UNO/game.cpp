#include "game.h"

game::game(unsigned n)
{
    h = new users;
    is_valid_move = false;
    is_first_move = true;
    h->number_players = 2;
    win1 = win2 = false;
}

void game::start_game()
{
    h->generate_deck();
    h->two_players();
}

void game::play_game(unsigned n)
{
    is_valid_move = false;
    std::string game_choice;
    if (h->get_player(1).size() == 0)
    {
        win1 = true;
    }
    else if (h->get_player(2).size() == 0)
    {
        win2 = true;
    }
    while (win1 == false && win2 == false)
    {
        if (is_first_move == true)
        {
            unsigned choice;
        first_move1:

            show_player(n);
            std::cout << "Drop your first card-Enter Number" << std::endl;
            std::cin >> choice;
            if (choice > h->get_player(n).size())
            {
                std::cout << "Enter a valid position";
                goto first_move1;
            }
            if (h->get_player(n)[choice - 1].get_number() == number_t::WILD || h->get_player(n)[choice - 1].get_number() == number_t::DRAW_FOUR_WILD)
            {
                h->get_player(n)[choice - 1] = card(get_color_change(), h->get_player(n)[choice - 1].get_number());
            }
            h->get_game_deck().push_back(h->get_player(n)[choice - 1]);
            h->get_player(n).erase(h->get_player(n).begin() + choice - 1);
            is_first_move = false;
            return;
        }
        if ((h->get_game_deck().back().get_number() == number_t::SKIP || h->get_game_deck().back().get_number() == number_t::REVERSE) && h->get_game_deck().back().power == true)
        {
            std::cout << "You lost a turn" << std::endl;
            h->get_game_deck().back().power = false;
            return;
        }

        if (h->get_game_deck().back().get_number() == number_t::DRAW_TWO && h->get_game_deck().back().power == true)
        {
            std::cout << "Two cards added" << std::endl;
            player_add(n);
            player_add(n);
            h->get_game_deck().back().power = false;
        }
        if (h->get_game_deck().back().get_number() == number_t::DRAW_FOUR_WILD && h->get_game_deck().back().power == true)
        {
            for (int i = 0; i < 4; i++)
            {
                player_add(n);
            }
            h->get_game_deck().back().power = false;
        }
        if (h->get_game_deck().back().get_number() == number_t::WILD || h->get_game_deck().back().get_number() == number_t::DRAW_FOUR_WILD)
        {
            std::cout << "The color is changed to " << h->get_game_deck().back().get_color_string() << std::endl;
        }
    label1:
        show_last();
        show_player(n);
        std::cout << "Enter drop for card_drop and add for taking a card" << std::endl;
        std::cin >> game_choice;

        if (game_choice == "drop")
        {
            if (is_move_available(n) == false)
            {
                std::cout << "No moves available to drop, You must add a card now" << std::endl;
                goto label1;
            }
            player_drop(n);
            return;
        }
        else if (game_choice == "add")
        {
            player_add(n);
            if (is_move_available(n) == false)
            {
                show_last();
                show_player(n);
                std::cout << "No moves available after adding" << std::endl;
                return;
            }
            else
            {
                show_last();
                show_player(n);
                char n;
                std::cout << "Do you want to drop anything?(Y/N) " << std::endl;
                std::cin >> n;
                if (n == 'Y')
                {
                    player_drop(n);
                    return;
                }
                else if (n == 'N')
                {
                    return;
                }
            }
        }
    }
}

void game::player_add(unsigned n)
{
    h->get_player(n).push_back(h->get_game_deck().front());
    h->get_player(n).back().power = true;
    h->get_game_deck().erase(h->get_game_deck().begin());
}

void game::player_drop(unsigned n)
{
    unsigned choice;
    do
    {
        std::cin >> choice;
        if (card_drop(n, choice) == false)
        {
            std::cout << "Invalid Choice" << std::endl;
        }
    } while (is_valid_move == false);
}

bool game::is_move_available(unsigned n)
{
    for (int i = 0; i < h->get_player(n).size(); i++)
    {
        if (h->get_player(n)[i].get_number() == number_t::WILD || h->get_player(n)[i].get_number() == number_t::DRAW_FOUR_WILD)
        {
            return true;
        }
        else if ((h->get_game_deck().back().get_number() >= number_t::DRAW_TWO) && h->get_player(n)[i].get_color() == h->get_game_deck().back().get_color())
        {
            return true;
        }
        else if ((h->get_game_deck().back().get_number() == number_t::SKIP || h->get_game_deck().back().get_number() == number_t::REVERSE) && (h->get_player(n)[i].get_number() == h->get_game_deck().back().get_number() || h->get_player(n)[i].get_color() == h->get_game_deck().back().get_color()))
        {
            return true;
        }
        else if ((h->get_game_deck().back().get_number() < number_t::SKIP) && (h->get_player(n)[i].get_number() == h->get_game_deck().back().get_number() || h->get_player(n)[i].get_color() == h->get_game_deck().back().get_color()))
        {
            return true;
        }
    }
    return false;
}
bool game::card_drop(unsigned t, unsigned n)
{
    is_valid_move = false;
    if (n > h->get_player(t).size())
    {
        is_valid_move = false;
    }
    else if (h->get_player(t)[n - 1].get_number() == number_t::WILD || h->get_player(t)[n - 1].get_number() == number_t::DRAW_FOUR_WILD)
    {
        is_valid_move = true;
    }
    else if (h->get_player(t)[n - 1].get_number() == number_t::DRAW_TWO && (h->get_player(t)[n - 1].get_color() == h->get_game_deck().back().get_color()))
    {
        is_valid_move = true;
    }
    else if ((h->get_player(t)[n - 1].get_number() == number_t::REVERSE || h->get_player(t)[n - 1].get_number() == number_t::SKIP) && (h->get_player(t)[n - 1].get_color() == h->get_game_deck().back().get_color() || h->get_player(t)[n - 1].get_number() == h->get_game_deck().back().get_number()))
    {
        is_valid_move = true;
    }
    else if (h->get_player(t)[n - 1].get_number() < number_t::SKIP && (h->get_player(t)[n - 1].get_number() == h->get_game_deck().back().get_number() || h->get_player(t)[n - 1].get_color() == h->get_game_deck().back().get_color()))
    {
        is_valid_move = true;
    }
    else if ((h->get_game_deck().back().get_number() >= number_t::DRAW_TWO) && h->get_player(t)[n - 1].get_color() == h->get_game_deck().back().get_color())
    {
        is_valid_move = true;
    }
    else if ((h->get_game_deck().back().get_number() == number_t::SKIP || h->get_game_deck().back().get_number() == number_t::REVERSE) && (h->get_player(t)[n - 1].get_number() == h->get_game_deck().back().get_number() || h->get_player(t)[n - 1].get_color() == h->get_game_deck().back().get_color()))
    {
        is_valid_move = true;
    }
    else if ((h->get_game_deck().back().get_number() < number_t::SKIP) && (h->get_player(t)[n - 1].get_number() == h->get_game_deck().back().get_number() || h->get_player(t)[n - 1].get_color() == h->get_game_deck().back().get_color()))
    {
        is_valid_move = true;
    }

    if (is_valid_move == true)
    {
        if (h->get_player(t)[n - 1].get_number() == number_t::WILD || h->get_player(t)[n - 1].get_number() == number_t::DRAW_FOUR_WILD)
        {
            h->get_player(t)[n - 1] = card(get_color_change(), h->get_player(t)[n - 1].get_number());
        }
        h->get_game_deck().push_back(h->get_player(t)[n - 1]);
        h->get_player(t).erase(h->get_player(t).begin() + n - 1);
        is_valid_move = true;
    }
    return is_valid_move;
}

void game::show_player(unsigned n)
{
    std::cout << "************" << std::endl;
    std::cout << "Player :" << n << std::endl;
    std::cout << "************" << std::endl;
    
    for (int i = 0; i < h->get_player(n).size(); i++)
    {
        std::cout << i + 1 << " ";
        h->get_player(n)[i].show_card();
    }
}

void game::show_last()
{
    std::cout << "................." << std::endl;
    std::cout << "DECK : ";
    h->get_game_deck().back().show_card();
    std::cout << "................." << std::endl;
}

color_t game::get_color_change()
{
    std::string c;
    color_t result;
redo:
    std::cout << "Enter the color you want to change to [Red,Blue,Green,Yellow] " << std::endl;
    std::cin >> c;
    if (c == "Red")
    {
        result = color_t::RED;
    }
    else if (c == "Blue")
    {
        result = color_t::BLUE;
    }
    else if (c == "Green")
    {
        result = color_t::GREEN;
    }
    else if (c == "Yellow")
    {
        result = color_t::YELLOW;
    }
    else
    {
        goto redo;
    }
    return result;
}