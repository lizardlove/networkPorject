#ifndef TIMERINTERFACE_H
#define TIMERINTERFACE_H

typedef struct _time {
    int ms;
    int s;
    int min;
    int hour;
} Time;

class TimerInterface
{
public:
    TimerInterface(int interval, bool needRepeat);
    
    virtual void callback() = 0;

    void setRegister();
    bool isRegisted();

    // void setTime(int ms, int s, int min, int hour);
    // Time getTime();

    void setTimerId(int id);
    int getTimerId();

    void setDest(int dest);
    int getDest();
    int getInterval();

    void stop();
    bool isStop();
    bool isNeedRepeat();


protected:
    int m_interval;
    bool m_isRegisted;
    bool m_needRepeat;
    bool m_isStop;
    int m_timerId;
    int m_dest;
    Time m_time;
};

#endif