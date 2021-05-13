#include "threadpool.h"
#include "thread_safe.h"
#include <cstdlib>
#include <chrono>
#include <algorithm>


void print_sum(int a, int b)
{
    std::cout<<a+b;
}

void print_prod(int a, int b)
{
    std::cout<<a*b;
}

constexpr std::pair<int, int> arr[] = {
 {2,3}, {3,4}, {-5, 6}, {9,90}, {-7,-7},
 {0,0}, {-12,-14}, {103,203}
};

int main()
{
    threadpool tp(2);
    constexpr size_t arrsz = sizeof(arr)/sizeof(std::pair<int,int>);

    for(int i=0;i<arrsz;i++)
    {
        tp.get_worklist()->push(print_sum,arr[i].first,arr[i].second);
        tp.get_worklist()->push(print_prod,arr[i].first,arr[i].second);
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));

    return EXIT_SUCCESS;
}