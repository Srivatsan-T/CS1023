#include"shape_factory.h"

shapes * ret_shape(shape_name t)
{
    switch(t)
    {
        case shape_name::shapes: return new shapes();
        case shape_name::rectangle: return new rectangle();
        case shape_name::circle: return new circle();
        default: return nullptr;
    }
}