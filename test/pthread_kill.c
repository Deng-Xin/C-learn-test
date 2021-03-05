/*************************************************************************************
 * Filename     : pthread_kill.c
 * Author       : XIN
 * Description  : 线程退出的几种方式
 *                1.return
 *                2.pthread_exit
 *                3.其他线程发来pthread_canel信号
 *                4.该进程中任意线程执行exit()，主线程main中的return相当于exit()
 * Date         : 2021-03-02 10:49:10
 * LastEditTime : 2021-03-05 14:47:55
 * Version      :
 * History      :
 *************************************************************************************/
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* func1(void* arg)
{
    printf("thread 1 return\n");
    return (void*)111;
}

void* func2(void* arg)
{
    printf("thread 2 pthread_exit\n");
    pthread_exit((void*)222);
}

void* func3(void* arg)
{
    while(1)//如果没有取消点（此函数中有系统调用），线程不会被取消，永远循环
    {
        printf("thread: Press any key to end me \n");
        sleep(1);
        pthread_testcancel();//自己设置取消点
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
