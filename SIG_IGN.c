#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int main()
{
    signal(2,SIG_IGN);
    while(1)
    {
        printf("2333\n");
        sleep(1);
    }
    return 0;
}