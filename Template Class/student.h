#ifndef _STUDENT_H
#define _STUDENT_H

#include<string>

class student
{
    std::string name;
    unsigned int height;
    unsigned int weight;
    
    public:
    student() = default;
    student(std::string,unsigned int ,unsigned int);
    unsigned int get_height();
    unsigned int get_weight();
    std::string get_name();
};


#endif