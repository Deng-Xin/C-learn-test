#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#define NET_ADDR 16
int main(void)
{
	struct hostent * host; 		/*定义一个结构指针，用于存放主机信息*/
	char addr_p[NET_ADDR];		/*存放点分十进制IP地址*/
	int i;
	if((host = gethostent()) == NULL)    /*获得主机信息*/
	{
		perror("fail to get host's information\n");
		exit(1);
	};
	printf("%s\n",host->h_name);		/*打印主机名*/
	for(i = 0; host->h_aliases[i] != NULL; i++)
		printf("%s\n", host->h_aliases[i]);		/*打印主机别名*/
	if(host->h_addrtype == AF_INET)				/*打印地址类型*/
		printf("af_inet\n");
	else
		printf("unix_inet\n");

	printf("%d\n",host->h_length);				/*打印地址长度*/
	for(i = 0; host->h_addr_list[i] != NULL; i++)
		/*把二进制地址转换为点分十进制地址并打印*/
		printf("%s\n",inet_ntop(host->h_addrtype, host->h_addr_list[i], addr_p, NET_ADDR));
	return 0;
}