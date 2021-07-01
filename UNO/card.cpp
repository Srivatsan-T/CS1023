#include "card.h"

card::card(color_t c, number_t n)
{
    color = c;
    number = n;
    power = true;
}

card::card()
{
    color = color_t::NO_COLOR;
    number = number_t::NO_NUMBER;
    power = true;
}

card::card(const card &s)
{
    color = s.color;
    number = s.number;
    power = s.power;
}

color_t card::get_color()
{
    return color;
}

number_t card::get_number()
{
    return number;
}

void card::show_card()
{
    std::string color = get_color_string();
    if (color == "RED")
    {
        color_change(12, color);
    }
    else if (color == "BLUE")
    {
        color_change(9, color);
    }
    else if (color == "GREEN")
    {
        color_change(10, color);
    }
    else if (color == "YELLOW")
    {
        color_change(14, color);
    }
    else if(color == "BLACK")
    {
        std::cout<<color;
    }
    std::string number = get_number_string();
    std::cout << ":" << number << std::endl;
}

std::string card::get_color_string()
{
    std::string color;
    if (get_color() == color_t::RED)
    {
        color = "RED";
    }
    else if (get_color() == color_t::BLUE)
    {
        color = "BLUE";
    }
    else if (get_color() == color_t::GREEN)
    {
        color = "GREEN";
    }
    else if (get_color() == color_t::YELLOW)
    {
        color = "YELLOW";
    }
    else if (get_color() == color_t::NO_COLOR)
    {
        color = "BLACK";
    }
    return color;
}

std::string card::get_number_string()
{
    std::string number;
    if (get_number() == number_t::ZERO)
    {
        number = "0";
    }
    else if (get_number() == number_t::ONE)
    {
        number = "1";
    }
    else if (get_number() == number_t::TWO)
    {
        number = "2";
    }
    else if (get_number() == number_t::THREE)
    {
        number = "3";
    }
    else if (get_number() == number_t::FOUR)
    {
        number = "4";
    }
    else if (get_number() == number_t::FIVE)
    {
        number = "5";
    }
    else if (get_number() == number_t::SIX)
    {
        number = "6";
    }
    else if (get_number() == number_t::SEVEN)
    {
        number = "7";
    }
    else if (get_number() == number_t::EIGHT)
    {
        number = "8";
    }
    else if (get_number() == number_t::NINE)
    {
        number = "9";
    }
    else if (get_number() == number_t::TEN)
    {
        number = "10";
    }

    if (get_number() == number_t::SKIP)
    {
        number = "SKIP";
    }

    else if (get_number() == number_t::REVERSE)
    {
        number = "REVERSE";
    }

    else if (get_number() == number_t::DRAW_TWO)
    {
        number = "DRAW-TWO";
    }

    else if (get_number() == number_t::WILD)
    {
        number = "WILD";
    }

    else if (get_number() == number_t::DRAW_FOUR_WILD)
    {
        number = "DRAW-FOUR-WILD";
    }
    return number;
}

void card::color_change(int color, std::string text)
{
    //1: Blue
    //2: Green
    //3: Cyan
    //4: Red
    //5: Purple
    //6: Yellow (Dark)
    //7: Default white
    //8: Gray/Grey
    //9: Bright blue
    //10: Brigth green
    //11: Bright cyan
    //12: Bright red
    //13: Pink/Magenta
    //14: Yellow
    //15: Bright white
    //Numbers after 15 include background colors
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    std::cout << text;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}