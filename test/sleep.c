#include <stdio.h>
#include <unistd.h>

int main()
{
    int i=0;
    while(1)
    {
        printf("%d\n",i);
        sleep(1);   // sleep()单位是秒,参数只能是整形
        usleep(500000);     // usleep()单位是us,参数只能是整形
        i++;
    }
    return 0;
}
