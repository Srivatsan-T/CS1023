#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <vector>
#include <thread>
#include <functional>
#include <list>
#include <mutex>
#include <limits>

#include "thread_safe.h"

void empty_queue()
{

}

void keep_working(thread_safe_worklist *wl)
{
    while(true)
    {
        std::optional<std::function<void ()>> work = wl->get();
        auto f = work.value_or(empty_queue);
        f();
    }
}

class threadpool
{
    unsigned num_thread;
    std::vector<thread_safe_worklist *> worklists;
    std::vector<std::thread *> workers;
    std::mutex m;

    void create_worker()
    {
        std::lock_guard<std::mutex> guard(m);
        if(workers.size() < num_thread)
        {
            thread_safe_worklist *wl = new thread_safe_worklist;
            worklists.push_back(wl);
            std::thread *t  = new std::thread(keep_working,worklists.back());
            workers.push_back(t);
        }
    }


    public:
    threadpool(unsigned a){num_thread = a;}
    
    thread_safe_worklist * get_worklist()
    {
        create_worker();
        unsigned min = std::numeric_limits<unsigned>::max();
        unsigned index;
        size_t sz = worklists.size();
        for(unsigned i=0;i<sz;i++)
        {
            size_t tmpsz = worklists[i]->size_of_worklist();
            if(tmpsz < min)
            {
                min = tmpsz;
                index=i;

            }
        }
        return worklists[index];

    }
};

#endif