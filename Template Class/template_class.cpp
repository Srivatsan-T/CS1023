#include<iostream>
#include"student.h"


template <typename T1, typename T2>
class my_pair
{
    public:
    my_pair(const T1 & _t1,const T2 & _t2)
    {
        first = _t1;
        second = _t2;
    }
    T1 getfirst()
    {
        return first;
    }
    T2 getsecond()
    {
        return second;
    }
    private:
    T1 first;
    T2 second;
};



int main()
{
    student s1("srivatsan",165,80);
    student s2("Girija",150,85);
    int a = 10;
    std::cout<<s1.get_name()<<':'<<s1.get_height()<<':'<<s1.get_weight()<<std::endl;
    //my_pair<int,int> p(10,19);
    //std::cout<<p.getfirst()<<':'<<p.getsecond()<<std::endl;
    my_pair<student,student> p(s1,s2);
    std::cout<<p.getfirst().get_height()<<':'<<p.getfirst().get_weight()<<':'<<p.getfirst().get_name()<<std::endl;
    std::cout<<p.getsecond().get_height()<<':'<<p.getsecond().get_weight()<<':'<<p.getsecond().get_name()<<std::endl;
    return 0;
}