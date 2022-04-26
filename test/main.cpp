#include <stdio.h>
#include <iostream>
#include <atomic>
#include <random>
#include "ThreadPool.h"


static int GetRandomTime(int intval)
{
    return random() % intval;
}
int main()
{
    srand(time(nullptr));
    std::atomic<int> count(0);
    {
        threadpool::ThreadPool pool(1, 4, 6);
        int n = 10000;
        while(n--){
            pool.AddTask([&](){
                ++count;
                std::this_thread::sleep_for(std::chrono::microseconds(GetRandomTime(1000)));
            });
            std::this_thread::sleep_for(std::chrono::microseconds(GetRandomTime(100)));
        }

        std::this_thread::sleep_for(std::chrono::seconds(7));

        n = 10000;
        while(n--){
            pool.AddTask([&](){
                ++count;
                std::this_thread::sleep_for(std::chrono::microseconds(GetRandomTime(1000)));
            });
            std::this_thread::sleep_for(std::chrono::microseconds(GetRandomTime(100)));
        }
    }
    printf("count:%d\n", count.load());
    return 0;
}