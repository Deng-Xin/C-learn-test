#include "socket.h"

int32_t main(int32_t argc, int8_t *argv[])
{
    if (argc < 3)
    {
        printf("Usage : ./client ip port \n");
        return -1;
    }

    int8_t sendbuf[MAX_LINE], recvbuf[MAX_LINE];
    int32_t sendlen, recvlen;

    printf("********** Client Start ********\n");
    int32_t sfd = TCP_Connect(argv[1], atoi(argv[2]));

    while (1)
    {
        printf("-------- Send --------\nplease enter: ");
        Gets(sendbuf, MAX_LINE);

        sendlen = send(sfd, sendbuf, sizeof(sendbuf), 0);
        if (sendlen != sizeof(sendbuf))
        {
            perror("fail to send");
            exit(-1);
        }

        if (strcmp(sendbuf, "quit") == 0)
        {
            printf("Quit\n");
            break;
        }

        printf("-------- RECEIVE --------\n");
        recvlen = recv(sfd, recvbuf, MAX_LINE, 0);
        if (recvlen > 0)
        {
            printf("contet is : %s\n",recvbuf);
        }
        else
        {
            perror("fail to recv");
        }
    }

    if (close(sfd == -1))
    {
        perror("fail to close");
        exit(-1);
    }

    return 0;
}
