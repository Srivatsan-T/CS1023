#include<iostream>
#include"rectangle.h"
#include"circle.h"

int main()
{
    int choice;
    std::cout<<"Enter 1 for circle and 2 for rectangle";
    std::cin>>choice;
    shapes *s;
    if(choice == 1)
    {
        s = new circle();
    }
    else if(choice == 2)
    {
        s = new rectangle();

    }
    std::cout<<s->to_shape();
    return 0;
}