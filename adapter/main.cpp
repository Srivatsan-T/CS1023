#include<array>
#include<iostream>
#include<optional>
#include<assert.h>
#include<stdexcept>

template<typename T,unsigned size>
class stack
{
    std::array<T,size> data;
    int index;

    public:

    stack()
    {
        index = -1;
    }

    bool push(T a) 
    {
        if(index == size)
        {
            return false;
        }
        for(int i=index;i>=0;i--)
        {
            data.at(i+1) = data.at(i); 
        }
            data.at(0) = a;
            index++;
            return true;
    }
    bool pop()
    {
        if(index == -1)
        {
            return false;
        }
        T item = data.at(0);
        for(int i=0;i<index;i++)
        {
            data.at(i) = data.at(i+1);
        }
        index--;
        return true;
    }

    std::optional<T> top()
    {
        if(index == -1)
        {
            return {};
        }
        else
        {
            return data.at(0);
        }
    }

    void show_stack()
    {
        for(int i=0;i<=index;i++)
        {
            std::cout<<data.at(i)<<":";
        }
        std::cout<<std::endl;
    }
};


int main()
{
    stack<int,4> s;
    auto v = s.top();
    assert(v.has_value() == false);
    try{
    for(int i=0;i<5;i++)
    {
        s.push(i);
        s.show_stack();
    }
    }
    catch(std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
        std::cout<<"Error ma"<<std::endl;
    }

    s.show_stack();
    for(int i=0;i<6;i++)
    {
        s.pop();
        s.show_stack();
    }
    return 0;
}