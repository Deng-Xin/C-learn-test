/*************************************************************************************
 * Filename     : signal.c
 * Author       : XIN
 * Description  : 捕捉信号与信号的处理方式 SIGINT是Ctrl+C
 * Date         : 2021-03-05 14:22:56
 * LastEditTime : 2021-03-05 14:41:28
 * Version      :
 * History      :
 *************************************************************************************/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

typedef void (*signal_handler)(int);

void signal_handler_fun(int signum)
{
    printf("catch signal %d\n", signum);
}

int main()
{
    /* 捕获信号后的三种处理方式：
        1.系统默认处理  SIG_DFL
        2.忽略该信号    SIG_IGN
        3.自定义处理：
            #include <signal.h>
            typedef void (*sighandler_t)(int);
            sighandler_t signal(int signum, sighandler_t handler);            */

    // /* 1.默认处理 */
    // signal(SIGINT, SIG_DFL);    /* Ctrl + C会强制退出程序 */

    // /* 2.忽略处理 */
    // signal(SIGINT, SIG_IGN);    /* Ctrl + C失效,按Ctrl + \可退出程序 */

    /* 3.默认处理 */
    signal(SIGINT, signal_handler_fun);    /* 按下Ctrl + C 会执行signal_hander_fun函数*/


    for (int i = 0; i < 10; i++)
    {
        printf("主函数仍在运行，%d 秒后退出\n", 10 - i);
        sleep(1);
    }
    return 0;
}