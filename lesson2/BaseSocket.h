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
#include "Addr.h"

typedef struct sockaddr_in scokIn;
typedef struct sockaddr_un sockUn;

using namespace std;

class BaseSocket
{
public:
	bool sendMessage(char* buf);
	bool recviveMessage(char* buf, int max);
	bool closeSocket();
	int socketId;
	BaseSocket(string domain, int port, string type, bool serverBool);
	BaseSocket(string domain, string ipc, string type, bool serverBool);
	
	BaseSocket();
    

private:
	// int socketId;
	int connectId;
	Addr server;
	struct sockaddr udpClient;
	bool addrFlag;
	bool connectType;
	bool serverFlag;
	virtual void creat();
};

#endif