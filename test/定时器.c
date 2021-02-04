#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <signal.h>
#include <time.h>


//简单打印信息，定时器触发函数
void SigHandle(int signo)
{
    printf("hello world\n");
}


void init_time()
{
    struct itimerval value;
    value.it_value.tv_sec=2; //定时器启动后，每隔2秒将执行相应的函数
    value.it_value.tv_usec=0;
    value.it_interval=value.it_value;
    setitimer(ITIMER_REAL,&value,NULL); //初始化 timer，到期发送 SIGPROF 信号
}

int main(int argc ,char *argv[]){


    signal(SIGALRM,SigHandle);
    init_time();
    for(;;);

    return 0;
}