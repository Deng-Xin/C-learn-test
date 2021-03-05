/*************************************************************************************
 * Filename     : malloc_free.c
 * Author       : XIN
 * Description  : malloc与free需成对使用,且free后的指针赋值为NULL,否则变为野指针
 * Date         : 2021-03-02 10:49:10
 * LastEditTime : 2021-03-05 14:49:28
 * Version      :
 * History      :
 *************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 100

int main()
{
    char * p = NULL;
    /*内存申请*/
    p = (char *)malloc(MAX_BUF_SIZE);

    /*内存初始化*/
    memset(p, '\0', MAX_BUF_SIZE);
    strcpy(p, "hello world");
    printf("%s\n",p);

    /*释放内存*/
    if (p != NULL)
    {
        free(p);
        /*在free之后给指针存储一个新值,否则会变成野指针*/
        p = NULL;
    }
    if (p != NULL)
    {
        /*发生错误*/
        strcpy(p, "wrong point");
        printf("%s\n",p);
    }
}