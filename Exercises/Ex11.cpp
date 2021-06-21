#include<iostream>
#include<map>
#include<vector>

template<typename T>
class multiset_t
{
    std::map<T,unsigned> set;
    public:
    multiset_t()
    {
        
    }
    void push(T a)
    {
        set.insert_or_assign(a,set.find(a)->second+1);
    }
    void pop_one(T a)
    {
        set.find(a)->second -= 1;
        if(set.find(a)->second == 0)
        {
            set.erase(a);
        }
    }
    void pop_all(T a)
    {
        set.erase(a);
    }
    void print_set()
    {
        for(const auto itr : set)
        {
            std::cout<<itr.first<<":"<<itr.second<<std::endl;
        }
        std::cout<<"Printing DOne"<<std::endl;
    }
    void print_array()
    {
        for(const auto itr : set)
        {
            for(int i=0;i<itr.second;i++)
            {
                std::cout<<itr.first<<":";
            }
        }
        std::cout<<std::endl;
    }
};


int main()
{
    multiset_t<int> t;
    t.push(1);
    t.push(2);
    t.push(1);
    t.print_set();
    for(int i=0;i<5;i++)
    {
        t.push(5);
    }
    t.print_set();
    t.print_array();
    t.pop_one(5);
    t.pop_one(2);
    t.print_set();
    t.pop_all(5);
    t.print_set();
    return 0;
}