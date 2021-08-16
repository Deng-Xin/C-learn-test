/*************************************************************************************
 * Filename     : getopt.c
 * Author       : XIN
 * Description  : 获取命令行参数函数getopt()
 * Date         : 2021-03-16 20:45:25
 * LastEditTime : 2021-03-16 20:51:44
 * Version      :
 * History      :
 *************************************************************************************/
#include <unistd.h>
#include <stdio.h>
int main(int argc, char * argv[])
{
    int aflag=0, bflag=0, cflag=0;
    int ch;
    printf("optind:%d，opterr：%dn",optind,opterr);
    printf("\n--------------------------\n");
    while ((ch = getopt(argc, argv, "ab:c:de::")) != -1)
    {
        printf("optind: %d,argc:%d,argv[%d]:%s\n", optind,argc,optind,argv[optind]);
        switch (ch) {
        case 'a':
            printf("HAVE option: -a\n");

            break;
        case 'b':
            printf("HAVE option: -b\n");

            printf("The argument of -b is %sn\n", optarg);
            break;
        case 'c':
            printf("HAVE option: -c\n");
            printf("The argument of -c is %s\n", optarg);

            break;
        case 'd':
            printf("HAVE option: -d\n");
            break;
        case 'e':
            printf("HAVE option: -e\n");
            printf("The argument of -e is %s\n", optarg);
            break;

        case '?':
            printf("Unknown option: %c\n",(char)optopt);
            break;
        }
    }
    printf("\n----------------------------\n");
    printf("optind=%d,argv[%d]=%sn",optind,optind,argv[optind]);
}