/*
 * scanf()会跳过空白
 * fgets()会在字符串中保留换行符
 * gets()由于可能超过目标缓冲区的大小所以不安全
 *
 * s_gets()获取用户每行的输入
 */
char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

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