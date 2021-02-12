#include <stdio.h>

int main()
{
    _Bool a = 1;
    _Bool b = 2;    /* 使用非零值，b的值为1 */
    _Bool c = 0;
    _Bool d = -1;   /* 使用非零值，d的值为1 */

    printf("a==%d\n", a);
    printf("b==%d\n", b);
    printf("c==%d\n", c);
    printf("d==%d\n", d);

    printf("sizeof(_Bool) == %lu\n", sizeof(_Bool));

    return 0;
}