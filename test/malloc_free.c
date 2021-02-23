/*
 * @File name: malloc_free
 * @Descripttion: malloc与free需成对使用,且free后的指针赋值为NULL,否则变为野指针
 * @version:
 * @Author: XIN
 * @Date: 2021-02-23 14:19:55
 * @LastEditors: XIN
 * @LastEditTime: 2021-02-23 14:36:04
 */

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