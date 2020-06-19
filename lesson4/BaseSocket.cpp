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
    if (serverBool) {
        serverFlag = true;
    } else {
        serverFlag = false;
    }
    server = base;
    string tcp = "TCP";
    if (type == tcp) {
        connectType = true;
    } else {
        connectType = false;
    }
    creat();
}
void BaseSocket::creat() {
    int type;
    if (connectType) {
        type = SOCK_STREAM;
    } else {
        type = SOCK_DGRAM;
    }
    if ((socketId = socket(AF_INET, type, 0)) == -1) {
        perror("socket() error.\n");
        exit(1);
    }
    if (!serverFlag) {
        if (connectType) {
            if (connect(socketId, (struct sockaddr *)&server, sizeof(server)) == -1) {
                printf("connect() error.\n");
                exit(1);
            }
        }
    } else {
        if (bind(socketId, (struct sockaddr *)&server, sizeof(server)) == -1) {
            perror("Bind() error.\n");
            exit(1);
        }
        cout << "bind ok." << endl;
        if (connectType) {
            if (listen(socketId, 5)==-1) {
                perror("listen() error.\n");
                exit(1);
            }
            // sockIn client;
            // socklen_t addrlen;
            // if((connectId = accept(socketId, (struct sockaddr *)&client, &addrlen)) == -1)
            // {
            //     perror("accept() error\n");
            //     exit(1);
            // }
        }

    }
}
void BaseSocket::trigger() {
    if (connectType) {
            sockIn client;
            socklen_t addrlen;
            if((connectId = accept(socketId, (struct sockaddr *)&client, &addrlen)) == -1)
            {
                perror("accept() error\n");
                exit(1);
            }
        }
}
void BaseSocket::closeSocket() {
    if (connectId) {
        close(connectId);
    }
    close(socketId);
}
void BaseSocket::closeSocket(int sockfd) {
    if (connectId == sockfd) {
        connectId = 0;
    }
    close(sockfd);
    
}

bool BaseSocket::sendMessage(char* buf) {
    if (connectType) {
        if (serverFlag) {
            write(connectId, buf, strlen(buf));
        } else {
            write(socketId, buf, strlen(buf));
        }
    } else {
        int num;
        if (serverFlag) {
            if((num = sendto(socketId , buf , strlen(buf) , 0 , (struct sockaddr *)&client ,  sizeof(client))) < 0)
            {
                perror("server sendto error");
                return false;
            }
        } else {
            if((num = sendto(socketId , buf , strlen(buf) , 0 , (struct sockaddr *)&server ,  sizeof(server))) < 0)
            {
                perror("client sendto error");
                return false;
            }
        }
    }
    return true;
}
int BaseSocket::recviveMessage(char* buf, int max) {
    int num;
    if (connectType) {
        if (serverFlag) {
            if((num = read( connectId, buf, max) ) == -1){
                perror("recvive() error.\n");
                return num;
            }
        } else {
            if((num = read( socketId, buf, max) )== -1){
                perror("recvive() error.\n");
                return num;
            }
        }
    } else {
        if (serverFlag) {
            socklen_t servlen = sizeof(client);
            if((num = recvfrom(socketId , buf , max, 0 ,(struct sockaddr *)&client , &servlen) ) < 0)
            {
                perror("recvfrom error");
                return num;
            }
        } else {
            if((num = recvfrom(socketId , buf , max, 0 , NULL , NULL) ) < 0)
            {
                perror("recvfrom error");
                return num;
            }
        }
    }
    return num;
}