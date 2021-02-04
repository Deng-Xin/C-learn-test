/*
函数原型: time_t time(time_t *timer)
参数说明: timer=NULL时得到当前日历时间（从1970-01-01 00:00:00到现在的秒数），timer=时间数值时，用于设置日历时间，time_t是一个unsigned long类型。如果 timer不为空，则返回值也存储在变量 timer中。
函数功能: 得到当前日历时间或者设置日历时间
函数返回: 当前日历时间

*/

#include <stdio.h>
#include <time.h>

int main()
{
    time_t t1,t2; //分别声明两种使用方式的赋值对象

    t1=time(0);   //第一种使用方式
    time(&t2);    //第二种使用方式

    printf("t1=%ld\n",t1);
    printf("t2=%ld",t2);

    return 0;
}