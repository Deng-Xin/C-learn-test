#include <stdio.h>
#include "enter.c"
#include "print.c"

static void delete_string(char str[],char ch);
int main()
{
    extern void enter(char str[]); // �Ժ���������
    extern void print(char str[]); // �Ժ���������
    char c,str[100];
    enter(str);
    scanf("%c",&c);
    delete_string(str,c);
    print(str);
    return 0;
}

static void delete_string(char str[],char ch)//�ڲ�����
{
    int i,j;
    for(i=j=0;str[i]!='\0';i++)
    if(str[i]!=ch)
    str[j++]=str[i];
    str[j]='\0';
}
