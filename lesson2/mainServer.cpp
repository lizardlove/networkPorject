#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/un.h>
#include "BaseSocket.h"

using namespace std;

int main() {
    BaseSocket sk("0.0.0.0", 6666, "UDP", true);
    cout << "server socket id: "<< sk.socketId << " opened." <<endl;
    char data[256];
    while(1){
        sk.recviveMessage(data, 256);
        cout << "server recvive: " << data << endl;
        sk.sendMessage(data);
    }
    sk.closeSocket();
    return 0;
}
