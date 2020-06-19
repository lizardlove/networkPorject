#ifndef ADVANCETIMEWHEEL_H
#define ADVANCETIMEWHEEL_H

#include <iostream>
#include <list>
#include <vector>
#include <mutex>
#include "TimeWheelInterface.h"
using namespace std;

template <class T>
class AdvanceTimeWheel : public TimeWheelInterface
{
public:
    AdvanceTimeWheel(int frequence, int wheelSize) {
        m_frequence = frequence;
        m_wheelSize = wheelSize;
        m_activeList = new std::vector<T*>[m_wheelSize];
    };

    ~AdvanceTimeWheel() = default;

    void updateActive() {
        for (int i = 0; i < m_list.size(); i++) {
            auto item = m_list[i];
            if (item->getDest() < m_Count*m_frequence*m_wheelSize) {
                int destIndex = getDestIndex(item->getDest());
                m_activeList[destIndex].push_back(item);
                m_list.erase(m_list.begin() + i);
                i--;
                continue;
            } else {
                break;
            }
        }
    };

    void run(int ms) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_lastTime += ms;
        if (m_pointer == 0) {
            m_Count++;
            updateActive();
        }
        if (m_lastTime % m_frequence == 0) {
            m_pointer = (m_pointer + 1) % m_wheelSize;
            auto timers = m_activeList[m_pointer];
            cout << "当前有" << timers.size() << "个定时器。" << endl;
            for (int i = 0; i < timers.size(); i++) {
                auto item = timers[i];
                item->callback();
                if (item->isStop()) {
                    timers.erase(std::begin(timers) + i);
                    i--;
                    m_timerCount--;
                    continue;
                }
                if (item->isNeedRepeat()) {
                    item->setDest(m_lastTime + item->getInterval());
                    int nextIndex = getDestIndex(item->getDest());
                    m_activeList[nextIndex].push_back(item);
                }
            }
            timers.clear();
            m_activeList[m_pointer].clear();
        }
    };
    void addTimer(T *timer) {
        if (timer->getInterval() % m_frequence != 0) {
            cout << "定时器最小间隔为" << m_frequence <<"ms。" << endl;
            return;
        }
        std::unique_lock<std::mutex> lock(m_mutex);
        int destTime = m_lastTime + timer->getDest();
        timer->setDest(destTime);
        timer->setTimerId(generateTimerId());
        if (destTime < m_Count * m_frequence*m_wheelSize) {
            int destIndex = getDestIndex(timer->getDest());
            m_activeList[destIndex].push_back(timer);
        } else {
            if (m_list.size() < 1 || destTime > m_list.back()->getDest()) {
                m_list.push_back(timer);
            } else {
                for (int i = 0; i < m_list.size(); i++) {
                    auto item = m_list[i];
                    if (item->getDest() > destTime) {
                        m_list.insert(m_list.begin()+i, timer);
                        break;
                    }
                }
            }
        }
        m_timerCount++;
    };
    int totalTimers() {
        return m_timerCount;
    };
    int getFrequence() {
        return m_frequence;
    };

private:
    int generateTimerId() {
        int x = rand() % 0xffffffff;
        int cur_time = time(nullptr);
        return x | cur_time | m_timerCount;
    };
    int getDestIndex(int dest) {
        return (dest / m_frequence) % m_wheelSize;
    };

private:
    int m_frequence;
    int m_wheelSize;
    int m_pointer = 0;
    int m_timerCount = 0;
    int m_Count = 0;
    int m_lastTime = 0;
    std::vector<T*> *m_activeList = nullptr;
    std::vector<T*> m_list;
    std::mutex m_mutex;
};

#endif