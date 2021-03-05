/*************************************************************************************
 * Filename     : 大小端字节序转换
 * Author       : XIN
 * Description  : 判断该系统是采用哪种字节序存储数据，并对大小端进行转换（4字节为单位）
 * Date         : 2021-03-02 10:49:10
 * LastEditTime : 2021-03-05 14:50:44
 * Version      :
 * History      :
 *************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void ConvertEndian(uint32_t *data)
{
   *data = ((*data & 0xff000000) >> 24)| ((*data & 0x00ff0000) >>  8)
         | ((*data & 0x0000ff00) <<  8)| ((*data & 0x000000ff) << 24);
}

int main()
{
    uint32_t i,num=0x12345678;
    uint8_t *buf;

    buf = (uint8_t *)(&num);
    printf("%x in this computer :\n",num);
    for (i = 0; i < 4; i++)
    {
        printf("%02X ",*(buf+i));
        printf("\n");
    }

    ConvertEndian(&num);
    buf = (uint8_t *)(&num);
    printf("%x in this computer :\n",num);
    for (i = 0; i < 4; i++)
    {
        printf("%02X ",*(buf+i));
        printf("\n");
    }

    return 0;
}