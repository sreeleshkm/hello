#include <iostream>
#include <pthread.h>
#include "types.h"

using namespace std;

bool exceedTime(uint32 lTimeDif, time_t &ulPrevTime);

void *thread1(void *threadId)
{
    time_t ulPreviousTime = 0;
    bool TimeState = false;
    uint8 Count = 0;

    while (true)
    {
        TimeState = exceedTime(5, ulPreviousTime);
        if (TimeState == true)
        {
            Count++;
            cout << "\bHi\n";
            if (Count == 2)
            {
                break;
            }
        }
    }

    pthread_exit(NULL);

    return NULL;
}

void *thread2(void *threadId)
{
    time_t ulPTime = 0;
    bool TimeState = false;
    while (true)
    {
        TimeState = exceedTime(3, ulPTime);
        if (TimeState == true)
        {
            cout << "\bHello\n";
        }
    }

    return NULL;
}

int main()
{
    char *Message1 = "Thread1";
    char *Message2 = "Thread2";
    pthread_t Thread1 = 0;
    pthread_t Thread2 = 0;
    // pthread_t Thread3 = 0;

    pthread_create(&Thread1, NULL, thread1, Message1);
    pthread_create(&Thread2, NULL, thread2, Message2);

    pthread_join(Thread1, NULL);
    pthread_join(Thread2, NULL);

    return 0;
}

bool exceedTime(uint32 lTimeDif, time_t &ulPrevTime)
{
    bool blDelayTime = false;
    time_t ulCurTime = 0;

    time(&ulCurTime);

    if ((ulCurTime - ulPrevTime) >= lTimeDif)
    {
        blDelayTime = true;
        ulPrevTime = ulCurTime;
        cout << "Unix time : " << ulCurTime << endl;
    }

    return blDelayTime;
}