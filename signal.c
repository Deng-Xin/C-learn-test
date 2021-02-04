#include<stdio.h>
#include<signal.h>
void  handler(int signo)//自定义一个函数处理信号
{
    printf("catch a signal:%d\n:",signo);
}
int main()
{
    signal(2,handler);
    while(1)
    {
        printf("1111\n");
        sleep(1);
    }
    return 0;
}