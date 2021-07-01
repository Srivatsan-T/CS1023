#include<iostream>
#include<thread>
#include<chrono>
template<typename T>
class singleton
{
    T data;
    singleton(){}

    //static singleton * instance;

    public:

    singleton(const singleton&) = delete;
    void operator=(singleton&) = delete; 

    static singleton& get_instance()
    {
        /*
        if(instance == nullptr)
        {
            std::this_thread::sleep_for(std::chrono::microseconds(200));
            std::cout<<"New instance alert";
            return new singleton();

        }
        else
        {
            return instance;
        }
        */
       static singleton instance; 
       return instance;
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

//template<typename T>
//singleton<T> * singleton<T>::instance = nullptr;

int main()
{
    //(singleton<int> :: get_instance()) ->set_data(20);
    //std::cout<<singleton<int> :: get_instance() ->get_data();

    std::thread b([](){singleton<int> * m = &singleton<int> :: get_instance();
                    m->set_data(100); std::cout<<m->get_data()<<std::endl;});

    singleton<int> * t = &singleton<int> :: get_instance();
    t->set_data(10);
    std::cout<<t->get_data()<<std::endl;
    std::cout<<"Hello";
    b.join();
    
    return 0;
}
