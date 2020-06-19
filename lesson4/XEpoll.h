#ifndef XEPOLL_H
#define XEPOLL_H

#include <sys/epoll.h>

#define MAX_EVENT_NUMBER 1024

class XEpoll
{
    public:
        XEpoll();
        XEpoll(int size);
        //~XEpoll();
        bool add(int socketId);
        bool del(int socketId);
        bool mod(int socketId, int type);
        int capture();

    public: 
        epoll_event events[MAX_EVENT_NUMBER];

    private:
        int m_fd;
};

#endif