#include<iostream>
#include"shape_factory.h"

int main()
{
    shapes *s1 = ret_shape(shape_name::rectangle);
    shapes *s2 = ret_shape(shape_name::circle);
    shapes *s3 = ret_shape(shape_name::shapes);
    std::cout<<s1->to_shape()<<std::endl<<s2->to_shape()<<std::endl<<s3->to_shape()<<std::endl;  
    return 0;
}