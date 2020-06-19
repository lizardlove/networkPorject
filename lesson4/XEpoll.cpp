#include <fcntl.h>
#include <errno.h>
#include <iostream>
#include <sys/epoll.h>
#include "XEpoll.h"
using namespace std;

XEpoll::XEpoll() {
    m_fd = epoll_create(32);
}
XEpoll::XEpoll(int size) {
    m_fd = epoll_create(size);
}
bool XEpoll::add(int socketId) {
    epoll_event event;
    event.data.fd = socketId;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl(m_fd, EPOLL_CTL_ADD, socketId, &event);
    
    int old_opt = fcntl(socketId, F_GETFL);
    int new_opt = old_opt | O_NONBLOCK;
    fcntl(socketId, F_SETFL, new_opt);
    return true;
}

int XEpoll::capture() {
    int num = epoll_wait(m_fd, events, MAX_EVENT_NUMBER, -1);
    if (num < 0) {
        cout << "epoll wait error" << endl;
        return 0;
    }
    return num;
    
}
bool XEpoll::del(int socketId) {
    int flag =  epoll_ctl(m_fd, EPOLL_CTL_DEL, socketId, 0);
    if (flag < 0) {
        return false;
    } else {
        return true;
    }
}
bool XEpoll::mod(int socketId, int type) {
    epoll_event ecvt;
    ecvt.data.fd = socketId;
    ecvt.events = type;
    int flag = epoll_ctl(m_fd, EPOLL_CTL_MOD, socketId, &ecvt);
    if (flag < 0) {
        return false;
    } else {
        return true;
    }
}