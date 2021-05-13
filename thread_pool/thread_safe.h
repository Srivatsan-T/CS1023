#ifndef _THREAD_SAFE_H
#define _THREAD_SAFE_H

#include <mutex>
#include <queue>
#include <functional>
#include <utility>
#include <optional>
#include <thread>
#include <iostream>


class thread_safe_worklist
{
    std::vector<std::function<void()>> q;
    std::mutex m;
    unsigned index = 0;

    public:

    template<typename F,typename... Args>
    void push(F fun,Args&& ...args)
    {
        std::lock_guard<std::mutex> guard(m);
        auto f = std::bind(std::forward<F> (fun),std::forward<Args> (args)...);
        q.emplace_back(std::function<void ()> ([f] {f();} ));
        ((std::cout<<args<<":"),...);
        std::cout<<std::endl;
    }

    std::optional<std::function<void ()>> get()
    {
        std::lock_guard<std::mutex> guard(m);

        if(index < q.size())
        {
            std::cout<<"Thread id"<<std::this_thread::get_id()<<"index and size"<<index<<":"<<q.size()<<std::endl;
            return q[index++];
        }
        return {};
    }

    int size_of_worklist()
    {
        return q.size()-index;
    }

    bool is_empty()
    {
        if(size_of_worklist() == 0)
        {
            return true;
        } 
        else
        {
            return false;
        }
    }
};

#endif