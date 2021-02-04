#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void ConvertToBigEndian(uint32_t *data)
{
   *data = ((*data & 0xff000000) >> 24)
         | ((*data & 0x00ff0000) >>  8)
         | ((*data & 0x0000ff00) <<  8)
         | ((*data & 0x000000ff) << 24);
};

int main()
{
    uint32_t i,num;
    uint8_t *uint32_buf,*test_buf,*tmp;
    uint32_t *buf = (uint32_t *)malloc(8);
    memset(buf,0,8);

    num = 0x12345678;
    *(buf+1) = num;

    ConvertToBigEndian(&num);
    uint32_buf = (uint8_t *)(&num);
    for (i = 0; i < 4; i++)
    {
        printf("uint32_buf: ");
        printf("%02X ",*(uint32_buf+i));
        printf("\n");
    }

    test_buf = (uint8_t *)(buf);
    for (i = 0; i < 8; i++)
    {
        printf("test_buf: ");
        printf("%02X ",*(test_buf+i));
        printf("\n");
    }

    ConvertToBigEndian(buf+1);
    test_buf = (uint8_t *)(buf);
    for (i = 0; i < 8; i++)
    {
        printf("new test_buf: ");
        printf("%02X ",*(test_buf+i));
        printf("\n");
    }

    // tmp = malloc(4);
    // memset(tmp,0,4);
    // for(i=0;i<4;i++)
    // {
    //     *(tmp+i) = *(uint32_buf+3-i);
    // }

    // memcpy(buf+1,tmp,4);

    // *buf = 0x00000001;
    // test_buf = (uint8_t *)(buf);
    // for (i = 0; i < 8; i++)
    // {
    //     printf("new test_buf: ");
    //     printf("%02X ",*(test_buf+i));
    //     printf("\n");
    // }

    return 0;
}