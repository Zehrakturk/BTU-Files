#include <stdio.h>
#include <stdlib.h>
//Nufus artis orani %1.5 olarak sabitlendi.
int main()
{
    int i=0;
    float nufus[1000],ikikat;
    nufus[0]=7968159020;
    float artis=119522385;

    printf("Yil\tDunya Nufusu\tNufus artis sayisi\t\n");
    for(; i<=75; i++)
    {
        printf("%d\t",i+2022);
        printf("%.0f\t",nufus[i]);
        nufus[i+1]=nufus[i]+artis;
        printf("%.0f",artis);
        artis=(float)nufus[i]*0.015;
        printf("\n");
    }
    for(i=0; i<=10000; i++)
    {
        nufus[i]+=artis;
        artis=(float)nufus[i]*0.015;
        ikikat=2*nufus[0];
        if(nufus[i]==ikikat)
        {
            printf("\nNufus %d yil sonra suanki nufusun iki kati olacak.\n",i);
        }
    }
}
