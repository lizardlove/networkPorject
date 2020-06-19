#include "Addr.h"

Addr::Addr() {}
Addr::Addr(struct sockaddr_in addr) {
    sin = addr;
}
Addr::Addr(struct sockaddr_un addr) {
    sun = addr;
}
Addr::operator struct sockaddr_in() {
    return sin;
}
Addr::operator struct sockaddr_un() {
    return sun;
}