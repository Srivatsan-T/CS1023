#include<array>
#include<iostream>
#include<optional>

template<typename T>

class stack
{
    std::array<T,100> data;
    int index;

    public:

    stack()
    {
        index = -1;
    }

    bool push(T a)
    {
        if(index >=100)
        {
            return false;
        }
        for(int i=index;i>=0;i--)
        {
            data[i+1] = data[i]; 
        }
        data[0] = a;
        index++;
        return true;
    }

    bool pop()
    {
        if(index == -1)
        {
            return false;
        }
        T item = data[0];
        for(int i=0;i<index;i++)
        {
            data[i] = data[i+1];
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
            return data[0];
        }
    }

    void show_stack()
    {
        for(int i=0;i<=index;i++)
        {
            std::cout<<data[i]<<":";
        }
        std::cout<<std::endl;
    }
};


int main()
{
    stack<int> s;
    for(int i=0;i<20;i++)
    {
        s.push(i);
    }
    s.show_stack();
    for(int i=0;i<5;i++)
    {
        s.pop();
    }
    s.show_stack();
    return 0;
}