// Server side C program to demonstrate Socket programming
#include "tcpListener.hpp"

#define PORT 8080
int main()
{
    tcplistener mylistener(PORT);
    mylistener.init();
    mylistener.run();
    return 0;
}
