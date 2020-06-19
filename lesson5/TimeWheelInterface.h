#ifndef TIMEWHEELINTERFACE_H
#define TIMEWHEELINTERFACE_H

class TimeWheelInterface
{
public:
    virtual void run(int ms) = 0;
    virtual int getFrequence() = 0;
};

#endif