#ifndef _SHAPE_FACTORY_H
#define _SHAPE_FACTORY_h

#include"shapes.h"
#include"rectangle.h"
#include"circle.h"

enum class shape_name{shapes,rectangle,circle};

shapes * ret_shape(shape_name);


#endif