/*************************************************************************************
 * Filename     :
 * Author       : XIN
 * Description  : 传递指针使子函数直接改变主函数的值
 * Date         : 2021-03-10 10:34:10
 * LastEditTime : 2021-03-15 21:20:04
 * Version      :
 * History      :
 *************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>    /* gettimeofday函数头文件 */
#include <unistd.h>      /* sleep函数头文件 */
void func(uint8_t * min)
{
    uint8_t * tmp;
    uint8_t a;
    tmp = & a;
    printf("1\n");
    *tmp = 0x10;
    printf("2\n");
    printf("tmp : %d\n", *tmp);
    *min = 0x10;
}


int32_t main(void)
{

    uint8_t min;

    func(&min);
    printf("%d\n", min);
    return 0;
}