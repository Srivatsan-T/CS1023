#ifndef _CIRCLE_H
#define _CIRCLE_H

#include<string>
#include"shapes.h"

class circle : public shapes
{
    public:
    std::string to_shape();
};

#endif