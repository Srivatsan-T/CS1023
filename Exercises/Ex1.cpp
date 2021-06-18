#include<iostream>
#include<vector>
#include<limits>
/*
The precondition is that T and U are comparable using >< operators and U is more precise than T 
*/

template<typename T>
T find_max()
{
    return std::numeric_limits<T>::min();
}

template<typename T, typename... U>
T find_max(T a, U... b)
{
    if(a > find_max(b...))
    {
        return a;
    }
    else
    {
        return find_max(b...);
    }
}

int main()
{
    std::cout<<find_max(10.75,1.5,12.2,20.5,3,8.43);
    return 0;
}