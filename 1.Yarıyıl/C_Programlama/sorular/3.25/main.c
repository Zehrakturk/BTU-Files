#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,a;
    char A;
    printf("%4c\t",'A');

    for(i=1;i<4;i++)
    {
        printf("%c+%d\t",'A',2*i);
    }
    printf("\n\n");
    for(i=1;i<6;i++)
    {
        printf("%4d\t",i*3);

        for(j=2;j<7;j+=2)
        {
            a=3*i+j;
            printf("%d\t",a);
        }
        printf("\n");
    }
    return 0;
}
