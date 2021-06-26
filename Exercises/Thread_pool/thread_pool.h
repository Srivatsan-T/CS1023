/*    Copyright (C) 2021  Saurabh Joshi

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef __THREAD_POOL_H
#define __THREAD_POOL_H

#include <vector>
#include <thread>
#include <functional>
#include <list>
#include <mutex>
#include "thread_safe_q.h"
#include <limits>

using worklistt = thread_safe_worklist_t;
/**
 * @brief empty_queue() function to act as default for std::optional
 * 
 */
void empty_queue()
{
    //    static unsigned i=0;
    //  fmt::print("empty_queue:Job queue was empty {}\n",i++);
}

/**
 * @brief keep_working is a function for the worker threads to 
 * take worklist wl, keep getting the work (std::function<void()>)
 * and execute it, if the worklist is empty it will return {} as 
 * part of std::optional 
 * 
 * @param wl worklist from which the thread will keep retrieving
 * work (std::function<void()>) and execute  
 */
void keep_working(worklistt *wl)
{
    while (true)
    {
        if (!wl->get_is_adding_done())
        {
            std::optional<std::function<void()>> work = wl->get();
            auto f = work.value_or(empty_queue);
            f();
        }
        else
        {
            if (!wl->empty())
            {
                std::optional<std::function<void()>> work = wl->get();
                auto f = work.value_or(empty_queue);
                f();
            }
            else
            {
                return;
            }
        }
    }
}

/**
 * @brief thread_pool_t is a thread pool class that creates up to
 * num_threads number of threads and similar number of threadsafe
 * worklist. Each thread will operate on its corresponding worklist.
 * 
 */
class thread_pool_t
{
    unsigned num_threads;               // number of threads in the thread pool
    std::vector<std::thread *> workers; // vector that stores pointers to worker threads
    std::vector<worklistt *> worklists; //vector that stores pointers to worklists
    std::mutex m;    
    static thread_pool_t* instance;                //mutex for thread-safety
    /**
     * @brief Create a worker object if pool is not saturated. Corresponding worklist
     * is also created in a thread-safe manner.
     * 
     */
    void create_workers()
    {
        if (workers.size() < num_threads)
        {
            std::lock_guard<std::mutex> guard(m);
            thread_safe_worklist_t *wl = new thread_safe_worklist_t;
            worklists.push_back(wl);
            std::thread *t = new std::thread(keep_working, worklists.back());
            workers.push_back(t);
        }
    }
    thread_pool_t(unsigned _nthreads)
    {
        num_threads = _nthreads;
    }

public:
    static thread_pool_t * get_instance(unsigned n)
    {
        if(!instance)
        {
            instance = new thread_pool_t(n);
        }
        return instance;
    }
    /**
     * @brief Get the worklist object which has the smallest
     *     number of pending "work" in the list. 
     * 
     * Caution: This is not thread-safe. Ideally, pool should be 
     * a singleton so that multiple objects are not present.
     * The worklist pointer that gets returned may not be the smallest
     * when it was returned (because it's not thread-safe). For our purpose
     * this is okay because we are just looking to assign work to a worker
     * which has "lesser" work. So a little bit of approximation is fine.
     * 
     * @return worklistt* , a pointer to the worklist having "lesser" work 
     */
    worklistt *get_worklist()
    {
        create_workers();
        unsigned min = std::numeric_limits<unsigned>::max();
        unsigned index;
        size_t sz = worklists.size();
        for (unsigned i = 0; i < sz; i++)
        {
            size_t tmpsz = worklists[i]->size();
            if (tmpsz < min)
            {
                min = tmpsz;
                index = i;
            }
        }
        return worklists[index];
    }

    void set_worklists_done()
    {
        for (unsigned i = 0; i < worklists.size(); i++)
        {
            worklists[i]->set_is_adding_done(true);
            workers[i]->join();
        }
    }
    std::vector<std::thread *> get_workers()
    {
        return workers;
    }
};

#endif