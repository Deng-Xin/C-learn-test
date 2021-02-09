#include <stdio.h>
#include <stdlib.h>

#define MAXSTU 50
typedef struct
{
    int age;
    float score;
    char name[100];
}Student_t;

void f(Student_t *q,int len)
{
    int i;

    for(i = 0; i < len; i++)
    {
        printf("请输入第%d个学生的信息:\n",i+1);

        scanf("%d",&q[i].age);

        scanf("%f",&q[i].score);

        scanf("%s",q[i].name);
        printf("\n");
    }
}


int main()
{
    int i;
    Student_t p[MAXSTU];
    int len = 3;
    f(p,len);

    for(i = 0; i < len; i++)
    {
        printf("\n");

        printf("age = %d\n",p[i].age);

        printf("score = %f\n",p[i].score);

        printf("name = %s",p[i].name);
        printf("\n");
    }

    return 0;
}