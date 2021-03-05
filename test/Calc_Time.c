/*************************************************************************************
 * Filename     : Calc_Time
 * Author       : XIN
 * Description  : 计算程序运行时间
 * Date         : 2021-03-05 14:11:37
 * LastEditTime : 2021-03-05 14:19:06
 * Version      : 1.0
 * History      :
 *************************************************************************************/
#include <stdio.h>
#include <sys/time.h>    /* gettimeofday函数头文件 */
#include <unistd.h>      /* sleep函数头文件 */

int main(void)
{
    struct timeval t0, t1;
    gettimeofday(&t0,NULL);
    sleep(2);
    gettimeofday(&t1,NULL);
    int use_time = (t1.tv_sec - t0.tv_sec)*1000000 + t1.tv_usec - t0.tv_usec;
    printf("Time : %uus\n",use_time);

    return 0;
}