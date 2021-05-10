#include<iostream>

template<typename T>
T max1(const T&a,const T&b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

template<typename T ,typename U>
T max2(const T &a, const U &b)
{
    if(a>b) return a;
    else return b;
}

int main()
{
    int a=10,b = 20;
    float c = 20.5;
    std::cout<<max1(a,b)<<':'<<max2(c,b)<<std::endl;

    int var = 10;
    int &ref = var;
    std::cout<<var<<':'<<ref<<std::endl;
    ref += 10;
    std::cout<<var<<':'<<ref<<std::endl; 
    return 0;
}