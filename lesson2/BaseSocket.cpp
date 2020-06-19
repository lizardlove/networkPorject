
#include "BaseSocket.h"


typedef struct sockaddr_in sockIn;
typedef struct sockaddr_un sockUn;


BaseSocket::BaseSocket(string domain, int port, string type, bool serverBool) {
    sockIn base;
    base.sin_family = AF_INET;
    base.sin_port = htons(port);
    const char *str=domain.c_str();
   //base.sin_addr.s_addr = htonl(inet_addr(str));
   base.sin_addr.s_addr = htonl(INADDR_ANY);
    Addr proxy(base);
    if (serverBool) {
        serverFlag = true;
    } else {
        serverFlag = false;
    }
    server = sockIn(proxy);
    string tcp = "TCP";
    if (type == tcp) {
        connectType = true;
    } else {
        connectType = false;
    }

    addrFlag = true;
    creat();
}
BaseSocket::BaseSocket(string domain, string ipc, string type, bool serverBool) {
    sockUn base;
    base.sun_family = AF_UNIX;
    strcpy(base.sun_path, "socketIPC");
    Addr proxy(base);
    if (serverBool) {
        serverFlag = true;
    } else {
        serverFlag = false;
    }
    server = sockUn(proxy);
    string tcp = "TCP";
    if (type == tcp) {
        connectType = true;
    } else {
        connectType = false;
    }
    addrFlag = false;
    creat();
}
void BaseSocket::creat() {
    int domain, type;
    if (addrFlag) {
        domain = AF_INET;
    } else {
        domain = AF_UNIX;
    }
    if (connectType) {
        type = SOCK_STREAM;
    } else {
        type = SOCK_DGRAM;
    }
    if ((socketId = socket(domain, type, 0)) == -1) {
        perror("socket() error.\n");
        exit(1);
    }
    if (!serverFlag) {
        if (connectType) {
            if (addrFlag) {
                struct sockaddr_in p = (sockIn)server;
                if (connect(socketId, (struct sockaddr *)&p, sizeof(p)) == -1) {
                    printf("connect() error.\n");
		            exit(1);
                }
            } else {
                struct sockaddr_un p = (sockUn)server;
                if (connect(socketId, (struct sockaddr *)&p, sizeof(p)) == -1) {
                    printf("connect() error.\n");
		            exit(1);
                }
            }
        }
    } else {
        if (addrFlag) {
            struct sockaddr_in p = (sockIn)server;
            if (bind(socketId, (struct sockaddr *)&p, sizeof(p)) == -1) {
                perror("Bind() error.\n");
                exit(1);
            }
            cout << "bind ok." << endl;
        } else {
            struct sockaddr_un p = (sockUn)server;
            if (bind(socketId, (struct sockaddr *)&p, sizeof(p)) == -1) {
                perror("Bind() error.\n");
                exit(1);
            }
        }
        if (connectType) {
            if (listen(socketId, 5)==-1) {
                perror("listen() error.\n");
                exit(1);
            }
           if (addrFlag) {
               sockIn client;
               socklen_t addrlen;
               if((connectId = accept(socketId, (struct sockaddr *)&client, &addrlen)) == -1)
                {
                    perror("accept() error\n");
                    exit(1);
                }
           } else {
               sockUn client;
               socklen_t addrlen;
               if((connectId = accept(socketId, (struct sockaddr *)&client, &addrlen)) == -1)
                {
                    perror("accept() error\n");
                    exit(1);
                }
           }
        }

    }
}

bool BaseSocket::closeSocket() {
    if (connectId){
        close(connectId);
    }
    close(socketId);
    return true;
}

bool BaseSocket::sendMessage(char* buf) {
    if (connectType) {
        if (serverFlag) {
            write(connectId, buf, strlen(buf));
        } else {
            write(socketId, buf, strlen(buf));
        }
    } else {
        if (addrFlag) {
            sockIn p = (sockIn)server;
            int num;
            if (serverFlag) {
                if((num = sendto(socketId , buf , strlen(buf) , 0 , &udpClient ,  sizeof(udpClient))) < 0)
                {
                    perror("server sendto error");
                    return false;
                }
            } else {
                if((num = sendto(socketId , buf , strlen(buf) , 0 , (struct sockaddr *)&p ,  sizeof(p))) < 0)
                {
                    perror("client sendto error");
                    return false;
                }
            }
        } else {
            sockUn p = (sockUn)server;
            if (serverFlag) {
                if(sendto(socketId , buf , strlen(buf) , 0 , &udpClient ,  sizeof(udpClient)) < 0)
                {
                    perror("server sendto error");
                    return false;
                }
            } else {
                if(sendto(socketId , buf , strlen(buf) , 0 , (struct sockaddr *)&p ,  sizeof(p)) < 0)
                {
                    perror("client sendto error");
                    return false;
                }
            }
        }
    }
    return true;
}
bool BaseSocket::recviveMessage(char* buf, int max) {
    if (connectType) {
        if (serverFlag) {
            if( read( connectId, buf, max) == -1){
                perror("recvive() error.\n");
                return false;
            }
        } else {
            if( read( socketId, buf, max) == -1){
                perror("recvive() error.\n");
                return false;
            }
        }
    } else {
        if (serverFlag) {
            socklen_t servlen = sizeof(udpClient);
            if( recvfrom(socketId , buf , max, 0 ,&udpClient , &servlen) < 0)
            {
                perror("recvfrom error");
                return false;
            }
        } else {
            if( recvfrom(socketId , buf , max, 0 , NULL , NULL) < 0)
            {
                perror("recvfrom error");
                return false;
            }
        }
    }
    return true;
}