#include<iostream>

template<typename T>
class singleton
{
    T data;
    singleton(){}

    static singleton * instance;

    public:

    singleton(const singleton&) = delete;
    void operator=(singleton&) = delete; 

    static singleton* get_instance()
    {
        if(instance == nullptr)
        {
            return new singleton();
        }
    }

    void set_data(T a)
    {
        data = a;
    }

    T get_data()
    {
        return data;
    }
};

singleton::instance = nullptr;

int main()
{
    singleton<int> * obj = singleton<int>::get_instance();
    obj->set_data(10);
    std::cout<<obj->get_data();
    return 0;
}
