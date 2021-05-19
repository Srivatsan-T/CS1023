#include "card.h"

card::card(unsigned c,unsigned n)
{
    color = c;
    number = n;
}

card::card()
{
    color = 0;
    number = 0;
}

card::card(const card &s)
{
    color = s.color;
    number = s.number;
}

unsigned card::get_color()
{
    return color;
}

unsigned card::get_number()
{
    return number;
}

void card::set_color(unsigned n)
{
    color = n;
}

void card::set_number(unsigned n)
{
    number = n;
}

void card::show_card()
{
    std::string color; 
    std::string number;
    if(get_color() == 0)
    {
        color = "RED";
    }
    else if(get_color() == 1)
    {
        color = "BLUE";
    }
    else if(get_color() == 2)
    {
        color = "GREEN";
    }
    else if(get_color() == 3)
    {
        color = "YELLOW";
    }
    else if(get_color() == 5)
    {
        color = "BLACK";
    }

    if(get_number() == 11)
    {
        number = "SKIP";
    }

    else if(get_number() == 12)
    {
        number = "REVERSE";
    }

    else if(get_number() == 13)
    {
        number = "DRAW-TWO";
    }
    
    else if(get_number() == 14)
    {
        number = "WILD";
    }
    
    else if(get_number() == 15)
    {
        number = "DRAW-FOUR-WILD";
    }

    if(get_color() != 5 && get_number()<11)
    {
        std::cout<<color<<":"<<get_number()<<std::endl;
    }
    else if(get_color() == 5)
    {
        std::cout<<color<<":"<<number<<std::endl;
    }
    else if(get_color() != 5 && get_number() >= 11)
    {
        std::cout<<color<<":"<<number<<std::endl;
    }
    
}