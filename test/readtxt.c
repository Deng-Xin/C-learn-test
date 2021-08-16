/*************************************************************************************
 * Filename     :
 * Author       : XIN
 * Description  :
 * Date         : 2021-06-10 17:02:07
 * LastEditTime : 2021-06-10 17:13:29
 * Version      :
 * History      :
 *************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{

    uint8_t *buf = (uint8_t *)malloc(20);
    int i, len = 10;

    FILE *fd;
    fd = fopen("file.txt", "r");

    for (i = 0; i < len; i++)
    {
        fscanf(fd, "%02X\n", buf+i);
    }

    fclose(fd);

    for (i = 0; i < len; i++)
    {
        printf("%02X ", *(buf + i));
    }

    printf("\n");
    return 0;
}