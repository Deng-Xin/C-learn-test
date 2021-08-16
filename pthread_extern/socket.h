#ifndef __TCP__NET_SOCKET__H
#define __TCP__NET_SOCKET__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <pthread.h>
#include <math.h>
#include <arpa/inet.h>
#include <linux/if_packet.h>
#include <net/if.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>

#define SERVER_PORT 8088
#define LINSEN_NUM 10
#define MAX_LINE 1400

typedef struct
{
    int sockfd;
    struct sockaddr_in c_addr;
}CLIENT_CONFIG_S;

int32_t TCP_Init(void);
void *  TCP_Accept(int32_t sfd);
int32_t TCP_Connect(const int8_t* ip, int32_t port);
int8_t * Gets(int8_t * st, int32_t n);

#endif