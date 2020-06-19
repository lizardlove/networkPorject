#include "TimerInterface.h"

TimerInterface::TimerInterface(int interval, bool needRepeat) {
    m_interval = interval;
    m_dest = interval;
    m_needRepeat = needRepeat;
    m_isStop = false;
    m_isRegisted  =false;
}

void TimerInterface::setRegister() {
    m_isRegisted = true;
}

bool TimerInterface::isRegisted() {
    return m_isRegisted;
}

// void TimerInterface::setTime(int ms, int s = 0, int min = 0, int hour = 0) {
//     m_time.ms = ms;
//     m_time.s = s;
//     m_time.min = min;
//     m_time.hour = hour;
// }

// Time TimerInterface::getTime() {
//     return m_time;
// }

void TimerInterface::setTimerId(int id) {
    m_timerId = id;
}

int TimerInterface::getTimerId() {
    return m_timerId;
}

void TimerInterface::setDest(int dest) {
    m_dest = dest;
}
int TimerInterface::getDest() {
    return m_dest;
}

int TimerInterface::getInterval() {
    return m_interval;
}


void TimerInterface::stop() {
    m_isStop = true;
}

bool TimerInterface::isStop() {
    return m_isStop;
}

bool TimerInterface::isNeedRepeat() {
    return m_needRepeat;
}