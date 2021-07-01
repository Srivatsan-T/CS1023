#include <chrono>
#include <iostream>
#include <mutex>
//#include <fmt/chrono.h>
#include <thread>
#include <list>
#include <vector>
#include <string>
#include<algorithm>

class ticker_listener_t
{
public:
    virtual void update(unsigned) = 0;
    virtual ~ticker_listener_t(){};
};

class string_listener_t
{
    public:
    virtual void update(std::string) = 0;
    virtual ~string_listener_t(){};
};

using listener_pairt = std::pair<ticker_listener_t *, bool>;
using string_pairt = std::pair<string_listener_t *, bool>;

class ticker_t
{
    unsigned seconds;
    std::vector<listener_pairt> listeners;
    std::mutex m;

public:
    ticker_t(unsigned _sec) : seconds(_sec)
    {
    }
    ~ticker_t()
    {
        //std::shared_ptr
        for (auto &l : listeners)
        {
            if (l.first != nullptr)
            {
                delete l.first;
            }
        }
    }
    unsigned subscribe(ticker_listener_t *tl)
    {
        const std::lock_guard<std::mutex> l(m);
        listener_pairt lp(tl, true);
        listeners.push_back(lp);
        return listeners.size() - 1;
    }
    void unsubscribe(unsigned index)
    {
        const std::lock_guard<std::mutex> l(m);
        listeners[index].second = false;
    }
    void start()
    {
        constexpr unsigned maxcount = 20;
        unsigned count = maxcount;
        std::cout << "Subroutine started\n";
        while (count > 0)
        {
            count--;
            //       fmt::print("Count is {}\n",count--);
            std::this_thread::sleep_for(std::chrono::seconds(seconds));
            std::lock_guard<std::mutex> l(m);
            for (auto l : listeners)
            {
                if (l.second)
                { //launch asynchronously
                    l.first->update(maxcount - count);
                }
            }
        }
    }
};

class reader_t
{
    std::vector<std::string> strings;
    unsigned seconds;
    std::vector<string_pairt> listeners;
    std::mutex m;

public:
    reader_t(unsigned sec, std::vector<std::string> str)
    {
        seconds = sec;
        strings = str;
    }
    ~reader_t()
    {
        //std::shared_ptr
        for (auto &l : listeners)
        {
            if (l.first != nullptr)
            {
                delete l.first;
            }
        }
    }

    unsigned subscribe(string_listener_t *tl)
    {
        const std::lock_guard<std::mutex> l(m);
        string_pairt lp(tl, true);
        listeners.push_back(lp);
        return listeners.size() - 1;
    }

    void unsubscribe(unsigned n)
    {
        const std::lock_guard<std::mutex> l(m);
        listeners[n].second = false;
    }

    void start()
    {
        unsigned maxcount = strings.size();
        unsigned count = maxcount;
        std::cout << "Subroutine started\n";
        while (count>0)
        {
            //       fmt::print("Count is {}\n",count--);
            std::this_thread::sleep_for(std::chrono::seconds(seconds));
            std::lock_guard<std::mutex> l(m);
            for (auto l : listeners)
            {
                if (l.second)
                {
                    l.first->update(strings[maxcount - count]);
                }
            }
            count--;
        }
    }
};

class print_string : public string_listener_t
{
    public:
    void update(std::string str)
    {
        std::cout<<str<<std::endl;
    }
    ~print_string(){}
};

class count_alpha : public string_listener_t
{
    public:
    void update(std::string str)
    {
        std::vector<char> char_list;
        for( auto&t : str)
        {
            std::cout<<t<<":"<<std::count(str.begin(),str.end(),t)<<"____";
        }
        std::cout<<std::endl;
    }
    ~count_alpha(){}
};

class print_tick_t : public ticker_listener_t
{
    unsigned tick_number = 0;

public:
    void update(unsigned tick_count)
    {
        std::cout << "This is tick number" << tick_count << "\n";
    }
    ~print_tick_t() {}
};

class print_hello_on_tick_t : public ticker_listener_t
{
public:
    void update(unsigned tick_count)
    {
        std::cout << "Tick Number:" << tick_count << "Hello\n";
    }
    ~print_hello_on_tick_t() {}
};

int main()
{
    /*
    ticker_t t1(5);
    // t1.subscribe(new print_tick_t());
    //    t1.subscribe(new print_hello_on_tick_t());
    //    t1.start();
    auto f = [&]()
    { t1.start(); };
    std::thread thr1(f);
    std::this_thread::sleep_for(std::chrono::seconds(15));
    unsigned ind1 = t1.subscribe(new print_hello_on_tick_t());

    std::this_thread::sleep_for(std::chrono::seconds(15));
    unsigned ind2 = t1.subscribe(new print_tick_t());
    std::this_thread::sleep_for(std::chrono::seconds(15));
    t1.unsubscribe(ind1);
    thr1.join();
    */
   std::vector<std::string> s = {"hello","how","srivatsan","hee","Girija","Pooja","Renu","Thiru","Sheep","Horse","Balaji","Vicky","Sudhakar","Gopi","Tamada","Man","fhiefhrf","ojrfffjf","ijefefjedjed","ffhhhhch","memmememe","cvcvvcufefif","jffjfjfj","fjrjfrf","eojfjfjfrf"};
   reader_t t2(3,s);
   auto g = [&]()
   {t2.start();};
   std::thread thr2(g);
   std::this_thread::sleep_for(std::chrono::seconds(6));
   unsigned ind3 = t2.subscribe(new print_string());
   std::this_thread::sleep_for(std::chrono::seconds(3));
   unsigned ind4 = t2.subscribe(new count_alpha());
   std::this_thread::sleep_for(std::chrono::seconds(9));
   t2.unsubscribe(ind3);
   thr2.join();
   return 0;
}