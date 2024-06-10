#include <thread>
#include "MMPlayer.h"
#include "MMThread/MMThread.h"
#include "MMAV/MMAV.h"

class MyThread : public MMThread
{
private:
    int a = 0;

public:
    MyThread(int _a)
    {
        a = _a;
    }
    ~MyThread() {}

    void run()
    {
        printf("print from thread %d\n", a);
    }
};

int main_thread(int argc, char const *argv[])
{
    printf("hello ...\n");
    MyThread t(9);
    t.Start();

    std::this_thread::sleep_for(std::chrono::seconds(2));

    return 0;
}

int main(int argc, char const *argv[])
{
    printf("hello MMPlayer...\n");
    MMAVReader reader;
    int ret;
    ret = reader.Open("E://a-download/train_rain.mp4");
    if (ret)
    {
        printf("open failed.\n");
        return -1;
    }

    int cnt = 0;
    while (1)
    {
        MMAVPacket packet;
        ret = reader.Read(&packet);
        if (ret)
        {
            break;
        }
        cnt++;
    }
    printf("read packet success: %d.\n", cnt);

    reader.Close();

    return 0;
}
