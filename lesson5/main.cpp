#include <iostream>
#include <thread>
#include "TimerInterface.h"
#include "TimeDriver.h"
#include "AdvanceTimeWheel.h"

using namespace std;

class AdvanceTimer : public TimerInterface
{
    public:
        AdvanceTimer(int interval, bool needRepeat) : TimerInterface(interval, needRepeat) {

        };
        void callback() {
            cout << "Timer ID: " << getTimerId() << " is callbacked." << endl;
        };
};


int main() {
    auto *driver = new TimeDriver(1000);
    auto *tw = new AdvanceTimeWheel<AdvanceTimer>(1000, 5);
    auto *timer = new AdvanceTimer(1000, false);
    auto *timer2 = new AdvanceTimer(2000, true);
    auto *timer3 = new AdvanceTimer(5000, false);
    tw->addTimer(timer);
    tw->addTimer(timer2);
    driver->mountTimeWheel(tw);
    driver->start();
    int n = 0;
    cout << "驱动器挂载了" << driver->totalTimeWheels() << "个时间轮。" << endl;
    while(n < 10) {
        this_thread::sleep_for(chrono::milliseconds(1000));
        if (n == 4) {
            tw->addTimer(timer3);
        }
        n++;
    }
    driver->stop();
    this_thread::sleep_for(chrono::milliseconds(1000));
    delete timer;
    delete timer2;
    delete tw;
    delete driver;
    return 0;
}