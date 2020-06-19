#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <ctype.h>
#include <iostream>

#include "Addr.h"
using namespace std;
typedef struct sockaddr_in sockIn;

class Test {
    public: 
        void* data;
        Test(int x) {
            if (x == 1) {
                int a = 1;
                data = &a;
            } else {
                double a = 1.1;
                data = &a;
            }
        };
};

class Complex
{
public:
Complex() {};
Complex(int x) {sun = x;cout<<x<<endl;}
Complex(double x) { sin = x;cout<<x<<endl;}
operator int() {return sun;} //类型转换函数
operator double() {return sin;} //类型转换函数
private:
int sun;
double sin;
};

int test(int x) {
    return x+2;
};
int main() {
    // Test* zxy = new Test(2);
    // cout << *(double*)(zxy->data) << endl;
    // Complex y(2);
    // struct sockaddr_in server;
    // server.sin_port = 9999;
    // Addr x(server);
    // cout << ((sockIn)x).sin_port << endl;

    char x[256];
    fgets(x, 256, stdin);
    char *y = x;
    cout << y <<endl;
    cout << strlen(y) <<endl;
}