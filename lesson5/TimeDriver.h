#ifndef TIMEDRIVER_H
#define TIMEDRIVER_H

#include <vector>
#include <mutex>
#include "TimeWheelInterface.h"

#define DEFAULT_GRANULARITY 10;

class TimeDriver
{
public:
    TimeDriver();
    TimeDriver(int granularity);
    ~TimeDriver();

    void mountTimeWheel(TimeWheelInterface* wheel);
    int totalTimeWheels();
    int getGranularity();
    void start();
    void stop();
    void loop();

private:
    bool m_stop = false;
    int m_granularity;
    std::mutex m_mutex;
    std::vector<TimeWheelInterface*> m_wheelList;
};

#endif