#include <arpa/inet.h>
#include <stdio.h>

int main()
{
    unsigned int hostOrder = 0x12345678;
    unsigned int networkOrder = htonl(hostOrder); //converts little endian to big endian
    printf("Network Byte Order: 0x%x\n", networkOrder);
    return 0;
}