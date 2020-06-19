#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/un.h>
#include "BaseSocket.h"

using namespace std;

int main() {
    BaseSocket sk("0.0.0.0", 6666, "TCP", false);
    cout << "client socket id: "<< sk.socketId << " connected." <<endl;
    char data[256];
    while(1){
        cout << "Input: "<< endl;
        fgets(data, 256, stdin);
        sk.sendMessage(data);
        sk.recviveMessage(data, 256);
        cout << " client recvive: " << data << endl;
    }
    sk.closeSocket();
    return 0;
}