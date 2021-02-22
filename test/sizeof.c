#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    unsigned long int a = 1;
    unsigned long b = 1;
    uint32_t c = 1;
    uint64_t d =1;

    printf("unsigned long int: %zd \n",sizeof(a));
    printf("unsigned long: %zd \n",sizeof(b));
    printf("uint32_t: %zd \n",sizeof(c));
    printf("uint64_t: %zd \n",sizeof(d));

    return 0;
}