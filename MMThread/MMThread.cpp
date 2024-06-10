#include <thread>

#include "MMThread.h"

int MMThread::Start()
{
    std::thread t(&MMThread::run, this);
    t.detach();

    return 0;
}