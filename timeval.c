
#include <sys/time.h>
#include <stdio.h>

int main(void)
{
    int i;
    struct timeval tv;

    for(i = 0; i < 4; i++){
            gettimeofday(&tv, NULL);
            printf("%d\t%d\n", tv.tv_usec, tv.tv_sec);
            // sleep(1);
    }

    return 0;

}