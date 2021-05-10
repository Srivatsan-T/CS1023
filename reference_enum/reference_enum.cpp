#include<iostream>
#include<string>

class employee
{
    std::string name;
    unsigned age;
    public:
    //employee() = default;
    //employee() = delete;
    //employee(employee &) = default;
    employee(employee &) = delete;
    employee(std::string _name,unsigned _age)
    {
        name = _name;
        age = _age;
    }
    const std::string& get_name()
    {
        return name;
    }
    const unsigned& get_age()
    {
        return age;
    }    
};

void ret_emp(employee &e)
{
    std::cout<<e.get_name()<<':'<<e.get_age()<<std::endl;
}

enum class Colors {RED,BLUE,GREEN,YELLOW};
enum class Weekends {SAT,SUN};


int main()
{
    employee emp("Srivatsan",18);
    ret_emp(emp);

    Colors col = Colors::RED;
    Weekends day = Weekends::SAT;
    if(col == Colors::GREEN)
    {
        std::cout<<"Not working";
    }
    else
    {
        std::cout<<"Working";
    }
    return 0;
}