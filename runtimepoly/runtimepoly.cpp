#include<iostream>


class shape
{
    public:
    //void to_shape()
    virtual void to_shape()
    {
        std::cout<<"This is cool";
    }
    virtual double get_area() = 0;
    //double get_area() = 0;
};


class rect : public shape
{
    double length;
    double breadth;
    public:
    rect(double a, double b)
    {
        length = a;
        breadth = b;
    }
    double get_area() //override
    {
        return length * breadth;
    }
    void to_shape() //override
    {
        std::cout<<"this is rectangle";
    }
    void rect_exclusive()
    {
        std::cout<<"Rectangle exclusive function";
    }
};

class circle : public shape
{
    double x_c;
    double y_c;
    double r;
    public:
    double get_area() //override
    {
        return 3.14 * r * r;
    }
    circle(double a, double b, double c)
    {
        x_c = a; 
        y_c = b;
        r = c;
    }
    void to_shape() //override
    {
        std::cout<<"this is circle";
    }
};


int main()
{
    shape * p = new rect(10,20);
    shape * q = new circle(0,0,10);
    std::cout<<p->get_area()<<std::endl;
    p->to_shape();
    //p->rect_exclusive();
    std::cout<<q->get_area()<<std::endl;
    q->to_shape();
    return 0;
}

/*
Here the base class pointer points to derived class
For this to work the base class and derived class must have functions of the same name
and the base class function must be virtual for it to use derived class's version
override works only for virtual functions and is optional
In 78 even though p is rect's object it cannot access rect_exclusive()
virtual keyword makes sure that function belonging to the object type is called, not the pointer's type
*/
