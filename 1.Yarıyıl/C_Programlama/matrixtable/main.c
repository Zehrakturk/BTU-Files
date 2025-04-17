#include <stdio.h>
#include <stdlib.h>
/*
int main()
{
    int i,j,n;
    printf("Kac sutunluk bir matris istersiniz.");scanf("%d",&n);
    int dizi[n][n];
    printf("\n\np ");
    for(i=0;i<n;i++)
    {
        printf("%4d",i);
    }
    printf("\nn\n");
    for(i=0;i<4*n+2;i++)
        printf("-");
    printf("\n");

    for(i=0;i<n;i++)
    {
        dizi[i][i]=1;
        dizi[i][0]=0;
        for(j=1;j<i;j++)
        {
            dizi[i][j]=dizi[i-1][j]+dizi[i-1][j-1];
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d --",i);
        for(j=0;j<=i;j++)
            printf("%4d",dizi[i][j]);
        printf("\n");
    }

}*/

int main()
{
    char dizi[10]="zehra";
    char *p1;
    p1=dizi;
    printf("%c",p1[4]);

}


