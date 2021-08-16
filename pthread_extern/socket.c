#include "socket.h"

int32_t TCP_Init(void)
{
    int32_t sfd = socket(AF_INET, SOCK_STREAM, 0);    //创建一个Socket
    if (sfd == -1)
    {
        perror("Fail to creat socket.");
        return(-1);
    }
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(struct sockaddr));
    serveraddr.sin_family = AF_INET;                  // IPV4
    serveraddr.sin_port   = htons(SERVER_PORT);       // 端口号
    serveraddr.sin_addr.s_addr = INADDR_ANY;          // 服务端可接收任意地址

    // 避免下次运行时由于端口被占用而导致的无法运行
    int32_t on = 1;
    if ((setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))) == -1)
    {
        perror("setsockopt failed");
        return(-1);
    }
    if ((bind(sfd, (struct sockaddr*)&serveraddr, sizeof(struct sockaddr))) == -1)
    {
        perror("bind");
        close(sfd);
        return(-1);
    }
    if ((listen(sfd, LINSEN_NUM)) == -1)
    {
        perror("listen");
        close(sfd);
        return(-1);
    }
    printf("Waiting for clients\n");

    return sfd;
}

void * TCP_Accept(int32_t sfd)
{
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(struct sockaddr));
    int32_t addrlen = sizeof(struct sockaddr);

    int32_t new_fd = accept(sfd, (struct sockaddr*)&client_addr, &addrlen);
    if (new_fd == -1)
    {
        perror("accept");
        close(new_fd);
        exit(-1);
    }
    printf("...connected from %s, port:%d, socket:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), new_fd);

    CLIENT_CONFIG_S * s_client = (CLIENT_CONFIG_S *)malloc(sizeof(*s_client));
    s_client->sockfd = new_fd;
    memcpy(&s_client->c_addr, &client_addr, sizeof(struct sockaddr));

    return (void *)s_client;
}

int32_t TCP_Connect(const int8_t* ip, int32_t port)
{
    int32_t sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1)
    {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(struct sockaddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = inet_addr(ip);

    if (connect(sfd, (struct sockaddr*)&serveraddr, sizeof(struct sockaddr)) == -1)
    {
        perror("connect");
        exit(-1);
        close(sfd);
    }
    printf("********* Connect to Server Success ********\n");

    return sfd;
}

int8_t * Gets(int8_t * st, int32_t n)
{
    int8_t * ret_val;
    int8_t * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');      // 查找换行符
        if (find)                     // 如果地址不是NULL
            *find = '\0';             // 在此放置一个空字符
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}