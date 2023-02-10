#include<iostream>
#include<thread>
#include<unistd.h>
#include<queue>
#include<mutex>

int main()
{
    std::queue<int> numbers;
    std::mutex mutex1;

    auto workers = [&](int workerNumber)
    {
        while(true)
        {
            bool has_worked = false;
            {
                std::scoped_lock lock(mutex1);
                if(!numbers.empty())
                {
                    std::cout << "I am worker " << workerNumber << " Numbers: " << numbers.front() << std::endl;
                    numbers.pop();

                    has_worked = true;
                }
            }

            if (has_worked)
                usleep(2500000); // simulating long work
            else
                usleep(1000);
        }
    };

    for (int i = 0; i < 3; i++)
    {
        auto worker = std::thread(workers, i);
        worker.detach();
    }

    auto scheduler = std::thread([&]
    {
        for(int i = 0; i < 10; i++)
        {
            {
                std::scoped_lock lock(mutex1);
                numbers.push(i);
                std::cout << "I am scheduler" << std::endl;
            }
            usleep(1000000); // simulating preparing samples
        }
    });

    scheduler.join();
    sleep(1);
}