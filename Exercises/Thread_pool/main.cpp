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

#include "thread_pool.h"
#include "thread_safe_q.h"
#include <cstdlib>
#include <chrono>
#include <algorithm>

// create a function to be given to a thread
// as a "work"
void print_sum(int a, int b)
{
    std::cout << "print_sum:" << a + b << "\n";
}

//another function to act as "work" to be put in the worklist
//of a worker thread
void print_mul(int a, int b)
{
    std::cout << "print_sum:" << a * b << "\n";
}

void print_max3(float a, float b, float c)
{
    std::cout << "Max item is :" << std::max(c, std::max(a, b)) << "\n";
}

//array of testcases
constexpr std::pair<int, int> arr[] = {
    {2, 3}, {3, 4}, {-5, 6}, {9, 90}, {-7, -7}, {0, 0}, {-12, -14}, {103, 203}};

thread_pool_t * thread_pool_t::instance = nullptr;

int main()
{
    thread_pool_t *tp = tp->get_instance(2); //initialize thread pool
    constexpr size_t arrsz = sizeof(arr) / sizeof(std::pair<int, int>);
    for (unsigned i = 0; i < arrsz; i++)
    {
        //push works in a worklist
        tp->get_worklist()->push(print_sum, arr[i].first, arr[i].second);
        //push works in a worklist
        tp->get_worklist()->push(print_mul, arr[i].first, arr[i].second);
    }
    tp->get_worklist()->push(print_max3, 3.4, 0, -1.3);
    tp->set_worklists_done();
    //sleep so as to allow other threads to work.
    //std::this_thread::sleep_for(std::chrono::seconds(5));

    //threads are not joined. As an exercise, change the code to use
    //join and graceful termination via flags instead of infinite-loop
    //of keep_working

    return EXIT_SUCCESS;
}