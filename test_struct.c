#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    int num;
    char name[20];
    float score[3];
}Student_t;

int main()
{
    Student_t *a[3];
    int i;
    for(i=0;i<3;i++)
    {
        a[i]=(Student_t *)malloc(sizeof(Student_t));
    }

    a[0]->num = 10;
    a[0]->name[0] = 'x';
    a[0]->score[0] = 10.0;

    free(a[1]);
    free(a[2]);
    a[1] = NULL;
    a[2] = NULL;

    for(i=0;i<3;i++)
    {
        if(a[i] == NULL)
        {
            printf("OK %d\n",i);
        }
    }


    return 0;
}