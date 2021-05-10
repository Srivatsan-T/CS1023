#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include<string>
#include"shapes.h"


class rectangle : public shapes
{
    public:
    std::string to_shape();
};

#endif