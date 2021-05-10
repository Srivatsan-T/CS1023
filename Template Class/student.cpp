#include"student.h"

student::student(std::string _name,unsigned int _h,unsigned int _w)
{
    name = _name;
    height = _h;
    weight = _w;
}

unsigned int student::get_height()
{
    return height;
}

unsigned int student::get_weight()
{
    return weight;
}

std::string student::get_name()
{
    return name;
}