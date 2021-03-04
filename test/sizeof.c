/*************************************************************************************
 * Filename     : sizeof.c
 * Author       : XIN
 * Description  : 测试常见整数类型所占字节数
 * Date         : 2021-03-02 10:49:10
 * LastEditTime : 2021-03-05 11:03:02
 * Version      :
 * History      :
 *************************************************************************************/
#include <stdio.h>
#include <stdint.h>

int main()
{
    /* Signed */
    signed char          a=1;
    short int            b=1;
    int                  c=1;
    long int             d=1;
    long long int        e=1;

    int8_t  f=1;
    int16_t g=1;
    int32_t h=1;
    int64_t i=1;

    /* 在printf中%d用于int或者比int小的整数类型。比int小的类型被转型成int。
       %ld用于long类型，%lld用于long long类型。 */

    printf("sizeof signed char   : %zd, %#x\n", sizeof(a), a);
    printf("sizeof short int     : %zd, %#x\n", sizeof(b), b);
    printf("sizeof int           : %zd, %#x\n", sizeof(c), c);
    printf("sizeof long int      : %zd, %#lx\n", sizeof(d), d);
    printf("sizeof long long int : %zd, %#llx\n", sizeof(e), e);

    printf("sizeof int8_t  : %zd, %#x\n", sizeof(f), f);
    printf("sizeof int16_t : %zd, %#x\n", sizeof(g), g);
    printf("sizeof int32_t : %zd, %#x\n", sizeof(h), h);
    printf("sizeof int64_t : %zd, %#lx\n", sizeof(i), i);

    return 0;
}