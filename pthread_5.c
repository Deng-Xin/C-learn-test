/*
编写一个程序，使用pthread_create函数循环创建5个线程，然后每次在
创建线程时将当前循环计数器的值通过pthread_create函数的arg参数传递
给新线程，在线程中打印输出该计数器的值。
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void * handle(void *arg)
{
    int i = (int)arg;
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    sleep(i);
    printf("\npid: %u tid: %u (0x%x)\n",(unsigned int)pid,(unsigned int)tid,(unsigned int)tid);
    printf("the number is : %d\n",i);
    pthread_exit(NULL);
}

int main()
{
    int i,err;
    pthread_t threadid;
    for(i=0;i<5;i++)
    {
        err = pthread_create(&threadid,NULL,handle,(void *)(i));
        if(err != 0)
        {
            printf("thread create is failed!\n");
            exit(0);
        }
        printf("the id in Main: %lu\n",threadid);
        pthread_detach(threadid);
    }
    sleep(5);
    return 0;
}