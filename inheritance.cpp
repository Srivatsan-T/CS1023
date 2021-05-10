#include<iostream>
#include<string>

class entity
{
    std::string name;
    protected:
    unsigned weight;
    unsigned volume;
    unsigned temperature;

    public:
    entity(std::string _name, unsigned _weight,unsigned _volume,unsigned _temperature)
    {
        name = _name;
        weight = _weight;
        volume = _volume;
        temperature = _temperature;
    }

    friend std::ostream& operator<<(std::ostream& out, entity e);
    entity operator+(entity e)
    {
        entity m(name,weight+e.weight,volume+e.volume,temperature+e.temperature);
        return m;
    }
    const std::string & getname() { return name; }
    unsigned getweight() { return weight; }
    unsigned getvolume() { return volume; }
    unsigned gettemp() { return temperature; }

};

std::ostream& operator<<(std::ostream& out, entity e)
{
    out<<"["<<e.name<<':'<<e.weight<<':'<<e.volume<<':'<<e.temperature<<']'<<std::endl;
    return out;
}

enum class reproduction {mitosis,meiosis};

class living : public entity
{
    protected:
    unsigned age;
    unsigned energy;
    bool is_multicellular;
    reproduction reproduction_type;

    public:
    living(std::string _name, unsigned _weight,unsigned _volume,unsigned _temperature,unsigned _age, unsigned _energy, bool _is_multicellular, reproduction _reproduction_type) : entity(_name,_weight,_volume,_temperature)
    {
        age = _age;
        energy = _energy;
        is_multicellular = _is_multicellular;
        reproduction_type = _reproduction_type;
    }
    unsigned getage() { return age; }
};

class mammals : public living
{
    unsigned limbs;

    public:
    unsigned get_numlimbs() { return limbs; }
};


//class pair to use operator overloading with template
template<typename T, typename U>
class pair
{
    T first;
    U second;
    public:
    pair(T _a, U _b)
    {
        first =_a;
        second = _b;
    }

    T getfirst() const{ return first; }
    U getsecond() const{ return second; }
    pair<T,U> operator+(pair<T,U> p);
};

template<typename T, typename U>
pair<T,U> pair<T,U> :: operator+(pair<T,U> p)
{
    pair<T,U> m(first+p.first,second+p.second);
    return m;
}

template<typename T,typename U>
std::ostream& operator<<(std::ostream& out, const pair<T,U>& p)
{
    out<<p.getfirst()<<':'<<p.getsecond()<<std::endl;
    return out;
}



int main()
{
    entity e("Srivatsan",80,1000,35);
    entity f("Srivatsan",80,1000,35);
    std::cout<<(e+f);
    std::cout<<e;

    pair<int,float> a(10,2.5);
    pair<int,float> b(30,7.5);
    std::cout<<a+b;
    return 0;
}

/*
There are 3 main ways to overload operators
1. to use friend keyword to use private members and have 2 different arguments
2. to not use friend keyword and use two different memebers and access using member functions (remove const for this to work) or add const afetr function parameters for every member func used
3. To not use friend keyword and use it as memeber function with 1 argument (the object itself becomes first argument)
*/