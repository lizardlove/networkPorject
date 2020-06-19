#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <errno.h>
#include "BaseSocket.h"
#include "XEpoll.h"

using namespace std;

int main() {
    XEpoll controller(5);
    BaseSocket sk("0.0.0.0", 6666, "TCP", true);
    cout << "server socket id: "<< sk.socketId << " opened." <<endl;
    controller.add(sk.socketId);
    char data[256];
    while(1){
        int number = controller.capture();
        if ((number < 0) && (errno != EINTR)) {
            cout << "epoll error" << endl;
        }
        cout << "Capture   " << number << " epoll" << endl;
        for (int i = 0; i < number; i++) {
            int currentId = controller.events[i].data.fd;
            if (currentId == sk.socketId) {
                sk.trigger();
                cout << "client socketId is " << sk.connectId << endl;
                controller.add(sk.connectId);
            } else if (controller.events[i].events & EPOLLIN) {
                int flag = sk.recviveMessage(data, 256);
                if (flag <= 0) {
                    sk.closeSocket(sk.connectId);
                    cout << "client closed" <<endl;
                } else {
                    cout << "server recvive: " << data << endl;
                    sk.sendMessage(data);
                }
            }
        }
    }
    sk.closeSocket();
    return 0;
}