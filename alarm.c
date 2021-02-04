#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>


static int counter;

void sig_alarm_handler(int sig_num)
{
    printf("%s, signal number:%d, counter:%d\n", __FUNCTION__, sig_num, counter);
    if(sig_num = SIGALRM)
    {
        counter++;
        int remaing = alarm(1);
        printf("re-alarm remaing:%d\n", remaing);
    }
}

int main()
{
    printf("hello world.\n");

    printf("pid number:%d\n", getpid());

    //拦截定时器信号。
    signal(SIGALRM, sig_alarm_handler);
    printf("signal() return ret address:%p,my sig_alm_handler:%p\n", pre, sig_alarm_handler); //pre应该是空才对。

    //设定定时器。
    int remaing = alarm(1);
    printf("alarm remaing:%d\n", remaing);//remaing 应该是0才对。
    counter = 0;

    while(counter < 7)
    {
        usleep(500);
    }

    //主动关闭定时器。
    alarm(0);
    printf("bye\n");

    return 0;
}