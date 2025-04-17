#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sayilar[101];
    int temp;
    int i;
    srand(time(0));
    for(i=0;i<101;i++)
    {
        sayilar[i]=rand()%1002;
    }
    for(i=0;i<102;i++)
    {
        for(int j=i+1;j<102;j++)
        {
            if(sayilar[i]>sayilar[j])
            {
                temp=sayilar[j];
                sayilar[j]=sayilar[i];
                sayilar[i]=temp;
            }
        }
    }
    for(i=0;i<102;i++)
    {
        printf("%d\n",sayilar[i]);
    }
            printf("Medyan:%d",sayilar[50]);
}
