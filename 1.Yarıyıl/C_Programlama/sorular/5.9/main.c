#include <stdio.h>
#include <stdlib.h>

int calculateCharges(float saat[3],float ucret[3])
{
    int i;
    float n,toplamsaat[3],toplamucret[3];

    for(i=1;i<=3;i++)
    {
        if(saat[i-1]>3.0)
        {
            n=saat[i-1]-3.0;
            ucret[i-1]=2.0+(n*0.50);
            if(saat[i-1]==24.0)
            {
                ucret[i-1]=10.0;
            }
        }
        else
        {
            ucret[i-1]=2.0;
        }
    }
    return(ucret);
}


int main()
{
    int i,j;
    float ucret[3], saat[3],toplamucret,toplamsaat;

    printf("Lutfen park saatini giriniz\n");

    for (i=0;i<3;i++)
    {
        scanf("%f",&saat[i]);
    }
    calculateCharges(saat,&ucret);
    printf("Araba\tSaat\tUcret\n");
    for(i=1;i<=3;i++)
    {
        printf("%d\t%.2f\t%.2f\t",i,saat[i-1],ucret[i-1]);
        printf("\n");
    }
    for(i=0;i<3;i++)
    {
        toplamucret+=ucret[i];
        toplamsaat+=saat[i];
    }
    printf("TOTAL\t%.2f\t%.2f\t",toplamsaat,toplamucret);
}
