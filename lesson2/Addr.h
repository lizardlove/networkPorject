#ifndef ADDR_H
#define ADDR_H

#include <netinet/in.h>
#include <sys/un.h>

class Addr {
    public:
        Addr();
        Addr(struct sockaddr_in addr);
        Addr(struct sockaddr_un addr);
        operator struct sockaddr_in ();
        operator struct sockaddr_un ();
    private:
        struct sockaddr_in sin;
        struct sockaddr_un sun;
};

#endif