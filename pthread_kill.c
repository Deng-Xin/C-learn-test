#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<pthread.h>

void* func1(void* arg)
{
    printf("thread 1 return\n");
    return (void*)111;
}

void* func2(void* arg)
{
    printf("thread 2 exit\n");
    pthread_exit((void*)222);
}

void* func3(void* arg)
{
    while(1)//如果没有取消点（此函数中有系统调用），线程不会被取消，永远循环
    {
        printf("thread:I will be killed in 3 seconds\n");
        sleep(1);
        pthread_testcancel();//自己设置取消点
        printf("cancel test\n");
    }
    return (void*)666;
}
int main(void)
{
    pthread_t tid;
    void * tret=NULL;
    int block;

    pthread_create(&tid,NULL,func1,NULL);
    pthread_join(tid,&tret);
    printf("thread 1 exit code = %d\n",(int)tret);

    pthread_create(&tid,NULL,func2,NULL);
    pthread_join(tid,&tret);
    printf("thread 2 exit code = %d\n",(int)tret);

    pthread_create(&tid,NULL,func3,NULL);
    // sleep(3);
    // printf("input to kill pthread3 :\n");
    block = getchar();      // 阻塞
    pthread_cancel(tid);
    pthread_join(tid,&tret);//回收已经取消的线程会返回-1
    printf("thread 1 exit code = %d\n",(int)tret);

    sleep(5);
    return 0;
}
