#ifndef BASESOCKET_H
#define BASESOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <iostream>

typedef struct sockaddr_in scokIn;
typedef struct sockaddr_un sockUn;

using namespace std;

class BaseSocket
{
public:
	bool sendMessage(char* buf);
	int recviveMessage(char* buf, int max);
    void trigger();
	void closeSocket();
    void closeSocket(int sockfd);

	int socketId;
    int connectId;
	BaseSocket(string domain, int port, string type, bool serverBool);
	BaseSocket();
    

private:
	struct sockaddr_in server;
    struct sockaddr_in client;
	bool connectType;
	bool serverFlag;
	virtual void creat();
};

#endif