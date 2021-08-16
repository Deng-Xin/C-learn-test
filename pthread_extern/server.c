#include "socket.h"

void * CLIENT_Handle(void *arg)
{
    CLIENT_CONFIG_S * s_client = (CLIENT_CONFIG_S *)arg;
    int32_t cfd = s_client->sockfd;
    struct sockaddr_in client_addr = s_client->c_addr;

    int8_t recvbuf[MAX_LINE], sendbuf[MAX_LINE];
    struct tcp_info info;
    int32_t info_len = sizeof(info);
    int32_t recvlen, sendlen;

    while (1)
    {
        getsockopt(cfd, IPPROTO_TCP, TCP_INFO, &info, (socklen_t *)&info_len);
        if (info.tcpi_state == TCP_ESTABLISHED)
        {
            printf("-------- RECEIVE --------\n");
            recvlen = recv(cfd, recvbuf, MAX_LINE, 0);
            if (recvlen > 0)
            {
                if(strcmp(recvbuf, "quit") == 0)
                {
                    printf("--------ip: %s, port: %d quit!--------\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                    break;
                }
                printf("content is : %s\n", recvbuf);
            }
            else
            {
                perror("fail to receive");
            }

            printf("-------- SEND --------\nplease enter: ");
            Gets(sendbuf, MAX_LINE);
            sendlen = send(cfd, sendbuf, sizeof(sendbuf), 0);
            if (sendlen != sizeof(sendbuf))
            {
                perror("fail to send");
                exit(-1);
            }
        }
        else
        {
            printf("--------ip: %s, port: %d disconnected!--------\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            break;
        }
    }
    if (close(cfd) == -1)
    {
        perror("fail to close");
        exit(-1);
    }
    free(s_client);

    return 0;
}


int32_t main(int32_t argc, int8_t* argv[])
{
    int8_t sendbuf[MAX_LINE], recvbuf[MAX_LINE];
    int32_t ret;
    int32_t sfd = TCP_Init();

    while(1)
    {
        CLIENT_CONFIG_S * s_client = (CLIENT_CONFIG_S *)TCP_Accept(sfd);

        pthread_t pth_client;
        ret = pthread_create(&pth_client, NULL, CLIENT_Handle, (void*)s_client);
        if (ret != 0)
        {
            perror("fail to creat CLIENT_Handle");
        }
        pthread_detach(pth_client);
    }

    if (close(sfd) == -1)
    {
        perror("fail to close");
        exit(-1);
    }

    return 0;
}
