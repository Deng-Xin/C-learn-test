/*
编写一个程序，使用pthread_create函数循环创建5个线程，然后每次在
创建线程时将当前循环计数器的值通过pthread_create函数的arg参数传递
给新线程，在线程中打印输出该计数器的值。
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void * pth2(void *arg)
{
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    printf("!! I am grandson: pid: %u tid: %u (0x%x)\n",(unsigned int)pid,(unsigned int)tid,(unsigned int)tid);
    pthread_exit(NULL);
}


void * pth1(void *arg)
{
    int i = (int)arg,err;
    pid_t pid;
    pthread_t tid,threadid;
    err = pthread_create(&threadid,NULL,pth2,NULL);
    if(err!=0)
    {
        printf("thread create is failed!\n");
        exit(0);
    }
    printf("%% The id in pth1: %lu %%\n",threadid);

    pid = getpid();
    tid = pthread_self();
    printf("@@ I am son pid: %u tid: %u (0x%x)\n",(unsigned int)pid,(unsigned int)tid,(unsigned int)tid);
    printf("the number is : %d\n",i);
    pthread_exit(NULL);
}

int main()
{
    int i,err;
    pthread_t threadid;
    for(i=0;i<5;i++)
    {
        err = pthread_create(&threadid,NULL,pth1,(void *)(i));
        if(err != 0)
        {
            printf("thread create is failed!\n");
            exit(0);
        }
        printf("** The id in Main: %lu **\n",threadid);
        pthread_detach(threadid);
    }
    sleep(3);
    return 0;
}