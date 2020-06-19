#include "TimeDriver.h"
#include <thread>
#include <iostream>

using namespace std;

TimeDriver::TimeDriver() {
    m_granularity = DEFAULT_GRANULARITY;
}
TimeDriver::TimeDriver(int granularity) {
    m_granularity = granularity;
}
TimeDriver::~TimeDriver(){
    stop();
}

void TimeDriver::mountTimeWheel(TimeWheelInterface *wheel) {
    if (wheel->getFrequence() % m_granularity != 0) {
        cout << "驱动器的时间粒度为"<< m_granularity << "ms，定时器的时间单位必须是驱动器时间粒度的整数倍。" << endl;
        return;
    }
    std::unique_lock<std::mutex> lock(m_mutex);
    m_wheelList.push_back(wheel);
}

int TimeDriver::totalTimeWheels() {
    return m_wheelList.size();
}

int TimeDriver::getGranularity() {
    return m_granularity;
}

void TimeDriver::start() {
    std::thread th([&]{
        this->loop();
    });
    th.detach();
} 
void TimeDriver::stop() {
    m_stop = true;
}

void TimeDriver::loop() {
    int nLoop = 0;
    while(true) {
        this_thread::sleep_for(chrono::milliseconds(m_granularity));
        std::unique_lock<std::mutex> lock(m_mutex);
        nLoop++;
        cout << "第" << nLoop << "次 tick: " << endl;
        for (int i = 0; i < m_wheelList.size(); i++) {
            m_wheelList[i]->run(m_granularity);
        }
        lock.unlock();
        if (m_stop) break;
    }
}